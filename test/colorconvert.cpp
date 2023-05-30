#include "colorconvert.h"

ColorConvert::ColorConvert()
{

}

 std::tuple<int,int,int> ColorConvert::RGBinCMY(int r, int g, int b){
     int c,m,y;
     c=255-r;
     m=255-g;
     y=255-b;
     return std::make_tuple(c,m,y);
 }

 std::tuple<int,int,int> ColorConvert::CMYinRGB(int c, int m, int y){
     int r,g,b;
     r=255-c;
     g=255-m;
     b=255-y;
     return std::make_tuple(r,g,b);
 }

 std::tuple<int,int,int> ColorConvert::RGBinHSL(int r, int g, int b){
      int h,s,l;
      double rr=r/255.0,rg=g/255.0,rb=b/255.0;
      double min = std::min(rr,std::min(rg,rb));
      double max = std::max(rr,std::max(rg,rb));

      if (max==min){
          return std::make_tuple(0,0,min*255);
      }

      s=(max-min)/(1-std::abs(1-(max+min)))*255;
      l=(min+max)/2*255;

      if (max==rr){
          h = int((rg-rb)/(max-min)*60+360)%360*255;
      }else if (max==rg){
          h = int((rb-rr)/(max-min)*60+120+360)%360*255;
      }else{
          h = int((rr-rg)/(max-min)*60+240+360)%360*255;
      }
      return std::make_tuple(int(h/360.0),s,l);
  }

  std::tuple<int,int,int> ColorConvert::HSLinRGB(int h, int s, int l){
      int rgb[3];

      double rh=h/255.0*360;
      double rs = s/255.0;
      double rl = l/255.0;
      double q;
      if (rl<0.5){
          q=rl*(rs+1);
      }else{
          q=rl+rs-(rl*rs);
      }
      double p =2*rl-q;

      double t[3];
      t[0]=(rh/360.0)+(1.0/3);
      t[1]=(rh/360.0);
      t[2]=(rh/360.0)-(1.0/3);

      for (int i=0;i<3;++i){
          if (t[i]<0) t[i]+=1;
          if (t[i]>1) t[i]-=1;

          if (t[i]<(1.0/6)){
              rgb[i]=(p+((q-p)*6*t[i]))*255;
          }else if (t[i]<(1.0/2)){
              rgb[i]=q*255;
          }else if (t[i]<(2.0/3)){
              rgb[i]=(p+((q-p)*6*((2.0/3)-t[i])))*255;
          }else{
              rgb[i]=p*255;
          }
      }

      return std::make_tuple(rgb[0],rgb[1],rgb[2]);
  }

  std::tuple<int,int,int> ColorConvert::RGBinHSV(int r, int g, int b){
       int h,s,v;

       double rr=r/255.0,rg=g/255.0,rb=b/255.0;
       double min = std::min(rr,std::min(rg,rb));
       double max = std::max(rr,std::max(rg,rb));

       if (max==min){
           if (max==0){
               return std::make_tuple(0,0,min*255);
           }else{
               return std::make_tuple(0,(1-(min/max))*255,min*255);
           }
       }

       if (max==rr){
           h = int((rg-rb)/(max-min)*60+360)%360*255;
       }else if (max==rg){
           h = int((rb-rr)/(max-min)*60+120+360)%360*255;
       }else{
           h = int((rr-rg)/(max-min)*60+240+360)%360*255;
       }
       s = (1-(min/max))*255;
       v=max*255;
       return std::make_tuple(h/360.0,s,v);
   }

  std::tuple<int,int,int> ColorConvert::HSVinRGB(int h, int s, int v){

      int rh=(int)(h/255.0*6)%6;
      double rs = s/255.0*100;
      double rv = v/255.0*100;

      double vm = (100-rs)*rv/100;
      double a = (rv-vm)*((int(h/255.0*360))%60/60.0);
      double vi = vm+a, vd = rv-a;

      rv=rv/100*255;
      vm=vm/100*255;
      vi=vi/100*255;
      vd=vd/100*255;

      switch (rh) {
      case 0:
          return std::make_tuple(rv,vi,vm);
          break;

      case 1:
          return std::make_tuple(vd,rv,vm);
          break;

      case 2:
          return std::make_tuple(vm,rv,vi);
          break;

      case 3:
          return std::make_tuple(vm,vd,rv);
          break;

      case 4:
          return std::make_tuple(vi,vm,rv);
          break;

      case 5:
          return std::make_tuple(rv,vm,vd);
          break;

      default:
          break;
      }
  }

  std::tuple<int,int,int> ColorConvert::RGBinYCbCr(int r, int g, int b,bool is601){
      double kb,kr;
      if (is601){
          kb=0.114;
          kr=0.299;
      }else{
          kb=0.0722;
          kr=0.2126;
      }
      double rr=r/255.0,rg=g/255.0,rb=b/255.0;
      double y,cb,cr;
      y=kr*rr+(1-kr-kb)*rg+kb*rb;
      cb=0.5*(rb-y)/(1-kb);
      cr=0.5*(rr-y)/(1-kr);
      return std::make_tuple(std::round(y*255),std::round((cb+0.5)*255),std::round((cr+0.5)*255));
  }

  std::tuple<int,int,int> ColorConvert::YCbCrinRGB(int ry, int rcb, int rcr, bool is601){
      double kb,kr,r,g,b;
      if (is601){
          kb=0.114;
          kr=0.299;
      }else{
          kb=0.0722;
          kr=0.2126;
      }
      double y=ry/255.0,cb=rcb/255.0-0.5,cr=rcr/255.540-0.5;

      b=(cb/0.5*(1-kb)+y);
      r=(cr/0.5*(1-kr)+y);
      g=((y-kr*r-kb*b)/(1-kr-kb));

      if (r>1){
          r=1;
      }
      if (r<0){
          r=0;
      }

      if (g>1){
          g=1;
      }
      if (g<0){
          g=0;
      }

      if (b>1){
          b=1;
      }
      if (b<0){
          b=0;
      }

      /*if (r<0||g<0||b<0){
          qDebug()<<r*255<<" "<<g*255<<" "<<b*255<<" "<<y<<" "<<cr<<" "<<cb;
      }*/
      return std::make_tuple((r*255),(g*255),(b*255));
  }

  std::tuple<int,int,int> ColorConvert::RGBinYCoCg(int r, int g, int b){
      double rr=r/255.0,rg=g/255.0,rb=b/255.0;
      double y = 0.25*rr+0.5*rg+0.25*rb;
      double co = 0.5*rr-0.5*rb;
      double cg = -0.25*rr+0.5*rg-0.25*rb;

      co+=0.5;
      cg+=0.5;
      if (y>1){
          y=1;
      }
      if (y<0){
          y=0;
      }

      if (cg>1){
          cg=1;
      }
      if (cg<0){
          cg=0;
      }

      if (co>1){
          co=1;
      }
      if (co<0){
          co=0;
      }

      return std::make_tuple(y*255,(co)*255,(cg)*255);
  }

  std::tuple<int,int,int> ColorConvert::YCoCginRGB(int ry, int rco, int rcg){
      double y=ry/255.0,co=rco/255.0-0.5,cg=rcg/255.0-0.5;
      double r=y+co-cg,g=y+cg,b=y-co-cg;

      if (r>1){
          r=1;
      }
      if (r<0){
          r=0;
      }

      if (g>1){
          g=1;
      }
      if (g<0){
          g=0;
      }

      if (b>1){
          b=1;
      }
      if (b<0){
          b=0;
      }

      return std::make_tuple(r*255,g*255,b*255);
  }
 /*
 mapping["YCbCr.601"]=3;
 mapping["YCbCr.709"]=4;
*/
