#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include "INYFI.H"

struct LADRILLO
{
 int ladrix,ladriy;
 int vida;
 int color;
} ladris [62];

void Inicio ();

main ()
{
 int i,j,k=0,m=45,mov=37,tecla=0,aux=0,pelx=40,pely=48,lado=0,verti=0;
 int pariz=16,parder=64,resistencia=1,soporte=49,diley=1,pendx=1,pendy=1;
 int n=0,chato=0,q=0,color=0,r=0,s=0,t=63,vidas=3,u=0,v=0;

 Presentacion ();

 Inicio ();

 textcolor (0);
 clrscr ();

// dibuja las lineas de los costados

 textcolor (18);
 for (i=1;i<=49;i++)
  {
   gotoxy (15,i);
   cprintf ("л\n\b");
  }
 for (j=1;j<=49;j++)
  {
   gotoxy (65,j);
   cprintf ("л\n\b");
  }

// ARRANCA CON LA POSTA RUTINA

 do
 {

  do
  {
 // dibula la paleta

   if (lado!=3)
   {
    textcolor (15);
    gotoxy (mov,49);
    cprintf ("ллллллл");
   }

 // dibuja los ladris

   if (color==0)
   {
    for (q=0;q<63;q++)
    {
     if (q==0)
      ladris[q].ladrix=18;
     else
     {
      ladris[q].ladrix=(ladris[q-1].ladrix)+5;
      if (ladris[q].ladrix==63)
       ladris[q].ladrix=18;
     }
     if (q<9)
      ladris[q].ladriy=3;
     else if ((q>=9) && (q<18))
      ladris[q].ladriy=5;
     else if ((q>=18) && (q<27))
      ladris[q].ladriy=7;
     else if ((q>=27) && (q<36))
      ladris[q].ladriy=9;
     else if ((q>=36) && (q<45))
      ladris[q].ladriy=11;
     else if ((q>=45) && (q<54))
      ladris[q].ladriy=13;
     else if ((q>=54) && (q<63))
      ladris[q].ladriy=15;

  // asignacion de colores a los ladris
     ladris[q].vida=1;
     s++;
     if (s==32)
      s=1;
     color=s;
     if (color==16)
      color=4;
     textcolor (color);
     gotoxy ((ladris[q].ladrix),(ladris[q].ladriy));
     cprintf ("лллл");
    }
   }

 // surutina de seleccion del lado de la pelota al principio

   if (lado==0)
    {
     if (tecla=='a' || tecla=='A')
      {
       lado=1;
      }
     if (tecla=='d' || tecla=='D')
      {
       lado=2;
      }
    }

 // subrutina de borrado la la ultima posicion para redibujar la paleta

   aux=mov;
   if ((tecla=='a' || tecla=='A') && (mov>=1))
   {
    mov=mov+7;
    gotoxy (mov,49);
    textcolor (0);
    cprintf ("л");
    textcolor (15);
    mov=aux;
    tecla=0;
   }
   else if ((tecla=='d' || tecla=='D') && (mov<=73))
   {
    mov=mov-1;
    gotoxy (mov,49);
    textcolor (0);
    cprintf ("л");
    textcolor (15);
    mov=aux;
    tecla=0;
   }

 // subrutina de borrado de los ladrillos

   for (q=0;q<63;q++)
   {
    if ((pelx==ladris[q].ladrix || pelx==(ladris[q].ladrix+1) || pelx==(ladris[q].ladrix+2) || pelx==(ladris[q].ladrix+3)) && (pely==ladris[q].ladriy) && (ladris[q].vida==1))
    {
     ladris[q].vida=0;
     sound (90);
     r++;
     t--;
     if (r==4)
     {
      m--;
      r=0;
     }
     if ((pelx==ladris[q].ladrix) && (chato==1))
     {
      lado=1;
      if (verti==0)
       verti=1;
      else
       verti=0;
     }
     if ((pelx==(ladris[q].ladrix+3)) && (chato==1))
     {
      lado=2;
      if (verti==0)
       verti=1;
      else
       verti=0;
     }
     if (verti==0)
      verti=1;
     else
      verti=0;
    }
    if (ladris[q].vida==0)
    {
     textcolor (0);
     gotoxy ((ladris[q].ladrix),(ladris[q].ladriy));
     cprintf ("лллл");
    }
   }


 // RUTINA DEL MOVIMIENTO DE LA PELOTA

   if (lado==0)
   {
    textcolor (15);
    gotoxy (pelx,pely);
    cprintf ("");
    gotoxy (68,3);
    cprintf ("VIDAS = %d",vidas);
   }

   v++;
   if (v==60)
   {
    nosound ();
    v=0;
   }

   // subrutina para ver si ganaste

   if (t==0)
   {
    clrscr ();
    gotoxy (23,25);
    textcolor (15);
    cprintf ("BIEN AHI LOCO!! GANASTE WACHIN !!");
    delay (3000);
    lado=3;
   }

   // subrutina de definicion de la trayectoria de la pelota
   if (pely==soporte)
    {
     lado=0;
     vidas--;
     if (vidas==0)
     {
      lado=3;
      clrscr ();
      gotoxy (20,25);
      textcolor (15);
      cprintf ("PERDISTE WACHIN, SOS UN GATO DE LOSHI");
      delay (3000);
      GameOver ();
      textcolor (0);
     }
     textcolor (0);
     for (u=pariz;u<(parder+1);u++)
     {
      gotoxy (u,soporte);
      cprintf ("л");
     }
     textcolor (15);
     mov=37;
     pelx=40;
     pely=48;
     verti=0;
     chato=0;
    }

    // si la pelota va para la izquierda y para arriba
   if ((lado==1) && (verti==0))
    {
     if ((pelx!=pariz) && (pely!=resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	pelx=pelx-pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely-pendy;
	  n=0;
	 }
	}
	else
	{
	 pely=pely-pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }

     if ((pelx==pariz) && (pely!=resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	lado=2;
	pelx=pelx+pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely-pendy;
	  n=0;
	 }
	}
	else
	{
	 pely=pely-pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }
     if ((pelx==pariz) && (pely==resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	lado=2;
	verti=1;
	pelx=pelx+pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely+pendy;
	  n=0;
	 }
	}
	else
	{
	 pely=pely+pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }
     if ((pelx!=pariz) && (pely==resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	verti=1;
	pelx=pelx-pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely+pendy;
	  n=0;
	 }
	}
	else
	{
	 pely=pely+pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }
    }

    //si la pelota va para la derecha y para arriba

   if ((lado==2) && (verti==0))
    {
     if ((pelx!=parder) && (pely!=resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	pelx=pelx+pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely-pendy;
	  n=0;
	 }
	}
	else
	{
	 pely=pely-pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }

     if ((pelx==parder) && (pely!=resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	lado=1;
	pelx=pelx-pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely-pendy;
	  n=0;
	 }
	}
	else
	{
	 pely=pely-pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }
     if ((pelx==parder) && (pely==resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	lado=1;
	verti=1;
	pelx=pelx-pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely-pendy;
	  n=0;
	 }
	}
	else
	{
	 pely=pely+pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }
     if ((pelx!=parder) && (pely==resistencia))
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	verti=1;
	pelx=pelx+pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely+pendy;
	  n=0;
	 }
	}
	else
	{
	pely=pely+pendy;
	}
	k=0;
       }
       k++;
       gotoxy (pelx,pely);
       cprintf ("");
       delay (diley);
      }
    }

    // si la pelota va para la izquierda y para abajo

   if ((lado==1) && (verti==1))
    {
     if (pelx!=pariz) // cuando no toca la pared
      {
       if ((pely==48) && (pelx==mov || pelx==(mov+1) || pelx==(mov+2) || pelx==(mov+3) || pelx==(mov+4) || pelx==(mov+5) || pelx==(mov+6)))
	{
	 if ((pelx==(mov+3)) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    verti=0;
	    pelx=pelx-pendx;
	    if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if ((pelx==(mov+2)) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    lado=1;
	    verti=0;
	    pelx=pelx-pendx;
	    if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if ((pelx==(mov+4)) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    lado=2;
	    verti=0;
	    pelx=pelx-pendx;
	    if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if (((pelx==mov) || (pelx==(mov+1))) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=1;
	   if (k>=m)
	   {
	    lado=1;
	    verti=0;
	    pelx=pelx-pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	if (((pelx==(mov+5)) || (pelx==(mov+6))) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=1;
	   if (k>=m)
	   {
	    lado=2;
	    verti=0;
	    pelx=pelx-pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	}
      else
      {
       textcolor (0);
       gotoxy (pelx,pely);
       cprintf ("л");
       textcolor (15);
       if (k>=m)
       {
	pelx=pelx-pendx;
	if (chato==1)
	{
	 n++;
	 if (n>=2)
	 {
	  pely=pely+pendy;
	  n=0;
	  }
	 }
	 else
	 {
	 pely=pely+pendy;
	 }
	 k=0;
	}
	k++;
	gotoxy (pelx,pely);
	cprintf ("");
	delay (diley);
       }
      }

     if (pelx==pariz)
      {
       if (pely==(soporte-1))
	{
	 if ((pelx==(mov+2)) || (pelx==(mov+3)) || (pelx==(mov+4)))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    lado=2;
	    verti=0;
	    pelx=pelx+pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if ((pelx==mov) || (pelx==(mov+1)) || (pelx==(mov+5)) || (pelx==(mov+6)))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=1;
	   if (k>=m)
	   {
	    lado=2;
	    verti=0;
	    pelx=pelx+pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }
	 else
	 {
	  textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   if (k>=m)
	   {
	    lado=1;     //ACA
	    pelx=pelx-pendx;
	    if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely+pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely+pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	 }


	}

       else
       {
	textcolor (0);
	gotoxy (pelx,pely);
	cprintf ("л");
	textcolor (15);
	if (k>=m)
	{
	 lado=2;
	 pelx=pelx+pendx;
	 if (chato==1)
	 {
	  n++;
	  if (n>=2)
	  {
	   pely=pely+pendy;
	   n=0;
	  }
	 }
	 else
	 {
	  pely=pely+pendy;
	 }
	 k=0;
	}
	k++;
	gotoxy (pelx,pely);
	cprintf ("");
	delay (diley);
       }
      }
    }

    // si la pelota va para la derecha y para abajo

   if ((lado==2) && (verti==1))
    {
     if (pelx!=parder) // cuando no toca la pared
      {
       if ((pely==48) && (pelx==mov || pelx==(mov+1) || pelx==(mov+2) || pelx==(mov+3) || pelx==(mov+4) || pelx==(mov+5) || pelx==(mov+6)))
	{
	 if ((pelx==(mov+3)) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    verti=0;
	    pelx=pelx+pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if ((pelx==(mov+2)) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    lado=1;
	    verti=0;
	    pelx=pelx+pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if ((pelx==(mov+4)) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    lado=2;
	    verti=0;
	    pelx=pelx+pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if (((pelx==mov) || (pelx==(mov+1))) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=1;
	   if (k>=m)
	   {
	    lado=1;
	    verti=0;
	    pelx=pelx+pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	if (((pelx==(mov+5)) || (pelx==(mov+6))) && (pely==48))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=1;
	   if (k>=m)
	   {
	    lado=2;
	    verti=0;
	    pelx=pelx+pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	}
       else
       {
	textcolor (0);
	gotoxy (pelx,pely);
	cprintf ("л");
	textcolor (15);
	if (k>=m)
	{
	 pelx=pelx+pendx;
	 if (chato==1)
	 {
	  n++;
	  if (n>=2)
	  {
	   pely=pely+pendy;
	   n=0;
	  }
	 }
	 else
	 {
	  pely=pely+pendy;
	 }
	 k=0;
	}
	k++;
	gotoxy (pelx,pely);
	cprintf ("");
	delay (diley);
       }
      }

     if (pelx==parder)
      {
       if (pely==(soporte-1))
	{
	 if ((pelx==(mov+2)) || (pelx==(mov+3)) || (pelx==(mov+4)))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=0;
	   if (k>=m)
	   {
	    lado=1;
	    verti=0;
	    pelx=pelx-pendx;
	     if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }

	 if ((pelx==mov) || (pelx==(mov+1)) || (pelx==(mov+5)) || (pelx==(mov+6)))
	  {
	   textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   chato=1;
	   if (k>=m)
	   {
	    lado=2;
	    verti=0;
	    pelx=pelx-pendx;
	    if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely-pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely-pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	  }
	 else
	 {
	  textcolor (0);
	   gotoxy (pelx,pely);
	   cprintf ("л");
	   textcolor (15);
	   if (k>=m)
	   {
	    lado=1;     //ACA
	    pelx=pelx-pendx;
	    if (chato==1)
	    {
	     n++;
	     if (n>=2)
	     {
	      pely=pely+pendy;
	      n=0;
	     }
	    }
	    else
	    {
	     pely=pely+pendy;
	    }
	    k=0;
	   }
	   k++;
	   gotoxy (pelx,pely);
	   cprintf ("");
	   delay (diley);
	 }


	}

       else
       {
	textcolor (0);
	gotoxy (pelx,pely);
	cprintf ("л");
	textcolor (15);
	if (k>=m)
	{
	 lado=1;
	 pelx=pelx-pendx;
	 if (chato==1)
	 {
	  n++;
	  if (n>=2)
	  {
	   pely=pely+pendy;
	   n=0;
	  }
	 }
	 else
	 {
	  pely=pely+pendy;
	 }
	 k=0;
	}
	k++;
	gotoxy (pelx,pely);
	cprintf ("");
	delay (diley);
       }
      }
    }
  }
  while (!kbhit());

  // subrutina de deteccion de teclas

  tecla=getch ();

  if ((tecla=='a' || tecla=='A') && (mov>=17))
   mov--;
  if ((tecla=='d' || tecla=='D') && (mov<=57))
   mov++;

 }
 while ((tecla!='p') && (lado!=3));
 return 0;
}

void Inicio ()
{
 textcolor (0);
 clrscr();

 textcolor (18);
 cprintf("                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 " лллллллл   лл           лллллллл   лллллллл   лл    лл   лллллллл   лллллллл \n\r"
	 " лл         лл           лл    лл   лл    лл   ллл  ллл   лл    лл   лл       \n\r"
	 " лл         лл           лл    лл   лл    лл   ллл  ллл   лл    лл   лл       \n\r"
	 " лл         лл           лл    лл   лл    лл   лллллллл   лл    лл   лл       \n\r"
	 " лл         лл           лл    лл   лл    лл   лллллллл   лл    лл   лл       \n\r"
	 " лл         лл           лл    лл   лл    лл   лл лл лл   лл    лл   лл       \n\r"
	 " лллллллл   лл           лллллллл   лл    лл   лл лл лл   лллллллл   лллллллл \n\r"
	 " лл         лл           лллл       лл    лл   лл лл лл   лл         лл       \n\r"
	 " лл         лл           лл лл      лл    лл   лл    лл   лл         лл       \n\r"
	 " лл         лл           лл  лл     лл    лл   лл    лл   лл         лл       \n\r"
	 " лл         лл           лл   лл    лл    лл   лл    лл   лл         лл       \n\r"
	 " лл         лл           лл    лл   лл    лл   лл    лл   лл         лл       \n\r"
	 " лллллллл   лллллллл     лл    лл   лллллллл   лл    лл   лл         лллллллл \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "         лл         лллллллл   лллллл     лллллллл    лл   лллллллл           \n\r"
	 "         лл         лл    лл   лл   лл    лл    лл    лл   лл    лл           \n\r"
	 "         лл         лл    лл   лл   лл    лл    лл    лл   лл    лл           \n\r"
	 "         лл         лл    лл   лл    лл   лл    лл    лл   лл    лл           \n\r"
	 "         лл         лл    лл   лл    лл   лл    лл    лл   лл    лл           \n\r"
	 "         лл         лл    лл   лл    лл   лл    лл    лл   лл                 \n\r"
	 "         лл         лллллллл   лл    лл   лллллллл    лл   лллллллл           \n\r"
	 "         лл         лл    лл   лл    лл   лллл        лл         лл           \n\r"
	 "         лл         лл    лл   лл    лл   лл лл       лл   лл    лл           \n\r"
	 "         лл         лл    лл   лл    лл   лл  лл      лл   лл    лл           \n\r"
	 "         лл         лл    лл   лл   лл    лл   лл     лл   лл    лл           \n\r"
	 "         лл         лл    лл   лл   лл    лл    лл    лл   лл    лл           \n\r"
	 "         лллллллл   лл    лл   ллллллл    лл     л    лл   лллллллл           \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r"
	 "                                                                              \n\r");


 delay (7000);
}
