kernel() {
  for( int k=39 ; k <= 44 ; k++ ) {
    for( int j=299 ; j <= 304 ; j++ ) {
      for( int i=299 ; i <= 304 ; i++ ) {
        float wFx=0, wFy=0, wFz=0, dsdp[27];
        wFx += qX0[0]*dwghi[i-ic+2]* wghj[j-jc+2]* wghk[k-kc+2];
        wFy +=  wghi[i-ic+2]*rX0[1]*dwghj[j-jc+2]* wghk[k-kc+2];
      
        wFx +=  wghi[i-ic+2]* wghj[j-jc+2]*sX0[0]*dwghk[k-kc+2];
        wFy +=  wghi[i-ic+2]* wghj[j-jc+2]*sX0[1]*dwghk[k-kc+2];
        wFz +=  wghi[i-ic+2]* wghj[j-jc+2]*sX0[2]*dwghk[k-kc+2];
      
        float hi=1.0/h;
        float hi2=hi*hi;
        float wFxdx0 =dwghix[i-ic+2]*  wghj[j-jc+2]*  wghk[k-kc+2]*hi*qX0[0];
        float wFxdy0 = dwghi[i-ic+2]* wghjy[j-jc+2]*  wghk[k-kc+2]*hi*rX0[1];
        float wFxdz0 = dwghi[i-ic+2]*  wghj[j-jc+2]* wghkz[k-kc+2]*hi*sX0[2];
      
        float wFydx0 = wghix[i-ic+2]* dwghj[j-jc+2]*  wghk[k-kc+2]*hi*qX0[0];
        float wFydy0 =  wghi[i-ic+2]*dwghjy[j-jc+2]*  wghk[k-kc+2]*hi*rX0[1];
        float wFydz0 =  wghi[i-ic+2]* dwghj[j-jc+2]* wghkz[k-kc+2]*hi*sX0[2];
      
        float wFzdx0 = wghix[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*sX0[2]*qX0[0];
        float wFzdy0 =  wghi[i-ic+2]* wghjy[j-jc+2]* dwghk[k-kc+2]*sX0[2]*rX0[1];
        float wFzdz0 =  wghi[i-ic+2]*  wghj[j-jc+2]*dwghkz[k-kc+2]*sX0[2]*sX0[2];
      
        if( kc <= Nz-3 ) { 
          wFxdx0 += dwghi[i-ic+2]*wghj[j-jc+2]* wghkz[k-kc+2]*hi*sX0[0] +
                    wghix[i-ic+2]*wghj[j-jc+2]* dwghk[k-kc+2]*hi*sX0[0] +
                    wghi[i-ic+2]*wghj[j-jc+2]*dwghkz[k-kc+2]*sX0[0]*sX0[0] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*(hi*dsX0[0]+sX0[0]*dsX0[2]);
      
          wFxdy0 += dwghi[i-ic+2]*  wghj[j-jc+2]* wghkz[k-kc+2]*hi*sX0[1] +
                    wghi[i-ic+2]*  wghjy[j-jc+2]* dwghk[k-kc+2]*hi*sX0[0] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*sX0[0]*sX0[1] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*(hi*dsX0[1]+sX0[1]*dsX0[2]);
      
          wFxdz0 += wghi[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*sX0[0]*sX0[2] +
                    wghi[i-ic+2]*  wghj[j-jc+2]*  dwghk[k-kc+2]*sX0[2]*dsX0[2];
      
          wFydx0 += wghi[i-ic+2]* dwghj[j-jc+2]* wghkz[k-kc+2]*hi*sX0[0] +
                    wghix[i-ic+2]* wghj[j-jc+2]* dwghk[k-kc+2]*hi*sX0[1] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*sX0[0]*sX0[1] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*(hi*dsY0[0]+sX0[0]*dsY0[2]);
      
          wFydy0 += wghi[i-ic+2]* dwghj[j-jc+2]* wghkz[k-kc+2]*hi*sX0[1] +
                    wghi[i-ic+2]* wghjy[j-jc+2]* dwghk[k-kc+2]*hi*sX0[1] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*sX0[1]*sX0[1] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*(hi*dsY0[1]+sX0[1]*dsY0[2]);//157
      
          wFydz0 += wghi[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*sX0[1]*sX0[2] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*sX0[2]*dsY0[2];//166
      
          wFzdx0 += wghi[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*sX0[0]*sX0[2] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*(hi*dsZ0[0] + sX0[0]*dsZ0[2]);//176
      
          wFzdy0 += wghi[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*sX0[1]*sX0[2] +
                    wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*(hi*dsZ0[1] + sX0[1]*dsZ0[2]);//188
      
          wFzdz0 += wghi[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*(sX0[2]*dsZ0[2]);//193
      
        }
      
        float wFxdx0dx0 = dwghixx[i-ic+2]*  wghj[j-jc+2]*  wghk[k-kc+2]*hi2*hi;
        float wFxdx0dy0 = dwghix[i-ic+2]*  wghjy[j-jc+2]*  wghk[k-kc+2]*hi2*hi;//200
        float wFxdx0dz0 = dwghix[i-ic+2]*  wghj[j-jc+2]*  wghkz[k-kc+2]*hi2*hi;
        float wFxdy0dy0 = dwghi[i-ic+2]* wghjyy[j-jc+2]*  wghk[k-kc+2]*hi2*hi;
        float wFxdy0dz0 = dwghi[i-ic+2]* wghjy[j-jc+2]*  wghkz[k-kc+2]*hi2*hi;
        float wFxdz0dz0 = dwghi[i-ic+2]*  wghj[j-jc+2]* wghkzz[k-kc+2]*hi2*hi;//212
      
        float wFydx0dx0 = wghixx[i-ic+2]* dwghj[j-jc+2]*  wghk[k-kc+2]*hi2*hi;
        float wFydx0dy0 = wghix[i-ic+2]* dwghjy[j-jc+2]*  wghk[k-kc+2]*hi2*hi;
        float wFydx0dz0 = wghix[i-ic+2]* dwghj[j-jc+2]*  wghkz[k-kc+2]*hi2*hi;
        float wFydy0dy0 = wghi[i-ic+2]*dwghjyy[j-jc+2]*  wghk[k-kc+2]*hi2*hi;
        float wFydy0dz0 = wghi[i-ic+2]*dwghjy[j-jc+2]*  wghkz[k-kc+2]*hi2*hi;
        float wFydz0dz0 = wghi[i-ic+2]* dwghj[j-jc+2]* wghkzz[k-kc+2]*hi2*hi;//230
      
        float wFzdx0dx0 = wghixx[i-ic+2]*  wghj[j-jc+2]* dwghk[k-kc+2]*hi2*hi;
        float wFzdx0dy0 = wghix[i-ic+2]*  wghjy[j-jc+2]* dwghk[k-kc+2]*hi2*hi;
        float wFzdx0dz0 = wghix[i-ic+2]*  wghj[j-jc+2]* dwghkz[k-kc+2]*hi2*hi;
        float wFzdy0dy0 = wghi[i-ic+2]* wghjyy[j-jc+2]* dwghk[k-kc+2]*hi2*hi;
        float wFzdy0dz0 = wghi[i-ic+2]* wghjy[j-jc+2]* dwghkz[k-kc+2]*hi2*hi;
        float wFzdz0dz0 = wghi[i-ic+2]*  wghj[j-jc+2]*dwghkzz[k-kc+2]*hi2*hi;//248
      
      
        float fx = -(mForces[0]*wFx+mForces[1]*wFy+mForces[2]*wFz)*jaci;//258
        float fy = -(mForces[1]*wFx+mForces[3]*wFy+mForces[4]*wFz)*jaci;
        float fz = -(mForces[2]*wFx+mForces[4]*wFy+mForces[5]*wFz)*jaci;//272
      
        dsdp[0] = -(mForces[0]*wFxdx0+mForces[1]*wFydx0 + mForces[2]*wFzdx0)*jaci;
        dsdp[1] = -(mForces[1]*wFxdx0+mForces[3]*wFydx0 + mForces[4]*wFzdx0)*jaci;
        dsdp[2] = -(mForces[2]*wFxdx0+mForces[4]*wFydx0 + mForces[5]*wFzdx0)*jaci;
        dsdp[3] = -(mForces[0]*wFxdy0+mForces[1]*wFydy0 + mForces[2]*wFzdy0)*jaci;
        dsdp[4] = -(mForces[1]*wFxdy0+mForces[3]*wFydy0 + mForces[4]*wFzdy0)*jaci;
        dsdp[5] = -(mForces[2]*wFxdy0+mForces[4]*wFydy0 + mForces[5]*wFzdy0)*jaci;
        dsdp[6] = -(mForces[0]*wFxdz0+mForces[1]*wFydz0 + mForces[2]*wFzdz0)*jaci;
        dsdp[7] = -(mForces[1]*wFxdz0+mForces[3]*wFydz0 + mForces[4]*wFzdz0)*jaci;
        dsdp[8] = -(mForces[2]*wFxdz0+mForces[4]*wFydz0 + mForces[5]*wFzdz0)*jaci;//335
        dsdp[9]  = -wFx*jaci;
        dsdp[10] =  0;
        dsdp[11] =  0;
        dsdp[12]  =-wFy*jaci;
        dsdp[13] = -wFx*jaci;
        dsdp[14] =  0;
        dsdp[15] = -wFz*jaci;
        dsdp[16] =  0;
        dsdp[17] = -wFx*jaci;
        dsdp[18] =  0;
        dsdp[19] = -wFy*jaci;
        dsdp[20] =  0;
        dsdp[21] =  0;
        dsdp[22] = -wFz*jaci;
        dsdp[23] = -wFy*jaci;
        dsdp[24] =  0;
        dsdp[25] =  0;
        dsdp[26] = -wFz*jaci;//353
      
        float_sw4 dddp[9], dh1[9], dh2[9], dh3[9];
        dddp[0]  =-wFxdx0*jaci;
        dddp[1]  =-wFxdy0*jaci;
        dddp[2]  =-wFxdz0*jaci;
        dddp[3]  =-wFydx0*jaci;
        dddp[4]  =-wFydy0*jaci;
        dddp[5]  =-wFydz0*jaci;
        dddp[6]  =-wFzdx0*jaci;
        dddp[7]  =-wFzdy0*jaci;
        dddp[8]  =-wFzdz0*jaci;//371
      
      
        dh1[0] = -(mForces[0]*wFxdx0dx0 + mForces[1]*wFydx0dx0+mForces[2]*wFzdx0dx0)*jaci;
        dh1[1] = -(mForces[0]*wFxdx0dy0 + mForces[1]*wFydx0dy0+mForces[2]*wFzdx0dy0)*jaci;
        dh1[2] = -(mForces[0]*wFxdx0dz0 + mForces[1]*wFydx0dz0+mForces[2]*wFzdx0dz0)*jaci;
      
        dh1[3] = dh1[1];
        dh1[4] = -(mForces[0]*wFxdy0dy0 + mForces[1]*wFydy0dy0+mForces[2]*wFzdy0dy0)*jaci;
        dh1[5] = -(mForces[0]*wFxdy0dz0 + mForces[1]*wFydy0dz0+mForces[2]*wFzdy0dz0)*jaci;
      
        dh1[6] = dh1[2];
        dh1[7] = dh1[5];
        dh1[8] = -(mForces[0]*wFxdz0dz0 + mForces[1]*wFydz0dz0+mForces[2]*wFzdz0dz0)*jaci;
      
        dh2[0] = -(mForces[1]*wFxdx0dx0 + mForces[3]*wFydx0dx0+mForces[4]*wFzdx0dx0)*jaci;
        dh2[1] = -(mForces[1]*wFxdx0dy0 + mForces[3]*wFydx0dy0+mForces[4]*wFzdx0dy0)*jaci;
        dh2[2] = -(mForces[1]*wFxdx0dz0 + mForces[3]*wFydx0dz0+mForces[4]*wFzdx0dz0)*jaci;
      
        dh2[3] = dh2[1];
        dh2[4] = -(mForces[1]*wFxdy0dy0 + mForces[3]*wFydy0dy0+mForces[4]*wFzdy0dy0)*jaci;
        dh2[5] = -(mForces[1]*wFxdy0dz0 + mForces[3]*wFydy0dz0+mForces[4]*wFzdy0dz0)*jaci;
      
        dh2[6] = dh2[2];
        dh2[7] = dh2[5];
        dh2[8] = -(mForces[1]*wFxdz0dz0 + mForces[3]*wFydz0dz0+mForces[4]*wFzdz0dz0)*jaci;
      
        dh3[0] = -(mForces[2]*wFxdx0dx0 + mForces[4]*wFydx0dx0+mForces[5]*wFzdx0dx0)*jaci;
        dh3[1] = -(mForces[2]*wFxdx0dy0 + mForces[4]*wFydx0dy0+mForces[5]*wFzdx0dy0)*jaci;
        dh3[2] = -(mForces[2]*wFxdx0dz0 + mForces[4]*wFydx0dz0+mForces[5]*wFzdx0dz0)*jaci;
      
        dh3[3] = dh3[1];
        dh3[4] = -(mForces[2]*wFxdy0dy0 + mForces[4]*wFydy0dy0+mForces[5]*wFzdy0dy0)*jaci;
        dh3[5] = -(mForces[2]*wFxdy0dz0 + mForces[4]*wFydy0dz0+mForces[5]*wFzdy0dz0)*jaci;
      
        dh3[6] = dh3[2];
        dh3[7] = dh3[5];
        dh3[8] = -(mForces[2]*wFxdz0dz0 + mForces[4]*wFydz0dz0+mForces[5]*wFzdz0dz0)*jaci;//497
      }
    }
  }
}
