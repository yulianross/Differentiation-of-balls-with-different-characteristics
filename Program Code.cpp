#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <ml.h>
#include<stdio.h>
#include<math.h>

int MinMax(long *Histograma);

void DibujarBox2D(IplImage *imagen,CvBox2D BoundBox);


int main()
{

	
	bool salir=FALSE;

	
	

do
{
	IplImage *im;
	char eleccion;
	bool j=TRUE;

	//Panel

	printf("Elija la imagen que quiere cargar\n");
	printf("Imagenes del programa:\n\n"
		   "A=2_bolas\n"
		   "B=3_bolas\n"
		   "C=4_bolas\n"
		   "D=6_bolas\n"
		   "E=bola_azul\n"
		   "F=bola_roja\n"
		   "G=bolas_cortadas\n"
		   "H=bola_amarilla_blanca\n"
		   "I=bola_amarilla_blanca_+intensidad\n"
		   "J=bola_amarilla1\n"
		   "K=bolas_cortadas_+intensidad\n"
		   "L=bolas_juntas\n"
		   "M=cambio_angulo_iluminacion\n"
		   "N=bolas_pegadas_1\n"
		   "O=bolas_pegadas_2\n"
		   "P=bolas_pegadas_3\n"
		   "Q=bolas_pegadas_4\n"
		   "R=bolas_pegadas_4_+intensidad\n"
		   "S=bolas_pegadas_rotas\n"
		   "T=bolas_pegadas_rotas_2\n"
		   

		   );

	printf("X=SALIR\n\n");

while(j==TRUE)
{
	

	
	scanf("%c",&eleccion);
	
	

	switch(eleccion)
	{
	case 'A':{   char NombreImagen[]="2_bolas.jpg"; im=cvLoadImage(NombreImagen, -1); j=FALSE;}
		    break;

	case 'B':  {char NombreImagen[]="3_bolas.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'C': { char NombreImagen[]="4_bolas.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'D':  { char NombreImagen[]="6_bolas.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'E':  { char NombreImagen[]="bola_azul.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;
		   
	case 'F':  {char NombreImagen[]="bola_roja.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'G':  {char NombreImagen[]="bolas_cortadas.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'H':  {char NombreImagen[]="bola_amarilla_blanca.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'I': { char NombreImagen[]="bola_amarilla_blanca_+intensidad.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'J': { char NombreImagen[]="bola_amarilla1.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'K':  { char NombreImagen[]="bolas_cortadas_+intensidad.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'L': { char NombreImagen[]="bolas_juntas.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'M':  {char NombreImagen[]="cambio_angulo_iluminacion.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'N':  {char NombreImagen[]="bolas_pegadas_1.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'O':  {char NombreImagen[]="bolas_pegadas_2.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'P':  {char NombreImagen[]="bolas_pegadas_3.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'Q':  {char NombreImagen[]="bolas_pegadas_4.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'R':  {char NombreImagen[]="bolas_pegadas_4_+intensidad.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'S':  {char NombreImagen[]="bolas_pegadas_rotas.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'T':  {char NombreImagen[]="bolas_pegadas_rotas_2.jpg"; im=cvLoadImage(NombreImagen, -1);j=FALSE;}
		    break;

	case 'X':  {salir=TRUE; return 0;}
		    break;


	default:{ printf("Eleccion incorrecta, vuelva a elegir una opcion\n"); j=TRUE; }
	}

}
		













	
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
//OBTENER UNA IMAGEN BINARIA SÓLO CON BOLAS AZULES Y OTRA SÓLO CON BOLAS ROJAS 

	
	
	IplImage *Imagen_RGB;
	
    
	
	IplImage *Imagen_umbr;
	IplImage *Imagen_umbr_2;
	


	CvSize Dimensiones;

	//umbrales de la imagenS y la imagenH. En esta parte no utilizo la función MinMax porque me sale mejor poniendo  unos umbrales fijos
	int umbral1=150;
	int umbral2=100;
	
	

	

	//pasamos de BGR a RGB

	Dimensiones= cvGetSize(im);

	Imagen_RGB=cvCreateImage(Dimensiones,IPL_DEPTH_8U,3);
	cvCvtColor(im,Imagen_RGB,CV_BGR2RGB);



	
IplImage *ImagenHSV;
IplImage *ImagenH,*ImagenS,*ImagenV;




//pasamos de RGB a HSV

ImagenHSV=cvCreateImage(Dimensiones,IPL_DEPTH_8U,3);

cvCvtColor(Imagen_RGB,ImagenHSV,CV_RGB2HSV);



//Extraemos de la imagen HSV sus tres componentes: H, S y V


ImagenH=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);
ImagenS=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);
ImagenV=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);
cvSplit(ImagenHSV,ImagenH,ImagenS,ImagenV,0);

//imagenes binarias para umbralizar Sy H

Imagen_umbr=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);
Imagen_umbr_2=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);

//umbralizacion.
cvThreshold(ImagenS,Imagen_umbr,umbral1,255,CV_THRESH_BINARY);

cvThreshold(ImagenH,Imagen_umbr_2,umbral2,255,CV_THRESH_BINARY_INV);



//Descompongo la imagen en R,G y B

IplImage *ImagenR=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);
IplImage *ImagenG=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);
IplImage *ImagenB=cvCreateImage(Dimensiones,IPL_DEPTH_8U,1);

cvSplit(Imagen_RGB,ImagenR,ImagenG,ImagenB,0);




//A partir de aquí hago una serie de transformaciones morfológicas para separar en imágenes binarias las bolas azules de las rojas.


    //creo elemento estructurante

	 IplConvKernel* element = 0;
     const int element_shape =CV_SHAPE_ELLIPSE;
	 int pos=1;
  
     element= cvCreateStructuringElementEx(pos*2+1,pos*2+1,pos,pos, element_shape,0);
	
	


    IplImage * temp= cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);
    IplImage *temp2=cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);
	IplImage *resta=cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);
	
	
	//con esto obtengo todas las bolas binarizadas
	
	cvMorphologyEx(Imagen_umbr,temp,temp, NULL,CV_MOP_TOPHAT,2);     //tophat. Me detecta sólo las sombras de las bolas. Mi iluminación iene de arriba.
	//cvMorphologyEx(Imagen_umbr,temp,temp, NULL,CV_MOP_BLACKHAT,2); Esto podria aplicarlo si las sombras se crearan en el lado contrario
	cvAbsDiff (Imagen_umbr, temp ,temp); //resto  la original - el tophat
	cvMorphologyEx(temp,temp,temp, NULL,CV_MOP_CLOSE,6); //aplico el cierre




	//Con esto obtengo las bolas azules binarizadas

	cvMorphologyEx(Imagen_umbr_2,temp2,temp2, NULL,CV_MOP_TOPHAT,1);     //tophat
	//cvMorphologyEx(Imagen_umbr,temp,temp, NULL,CV_MOP_BLACKHAT,2);
	cvAbsDiff (Imagen_umbr_2, temp2 ,temp2); //resto  la original - el tophat
	cvMorphologyEx(temp2,temp2,temp2, NULL,CV_MOP_CLOSE,6); //aplico el cierre

	//Dilato y erosiono el mismo número de veces, para que las bolas me queden mas o menos del mismo tamaño. Además lo hago muchas veces(15), para eliminar los
	//máximos defectos posibles debido a sombras y cambios y contrastes debido a la iluminación
	cvDilate(temp2,temp2,element,15);

	cvErode(temp2,temp2,element,15);


	cvAbsDiff (temp2, temp ,resta); // Resto la imagen de todas las bolas -la imagen de las bolas azules, dilato mcuhas veces y erosiono muchas veces,
	//y finalmente solo me quedan las rojas
	cvDilate(resta,resta,element,15);//dilato

	cvErode(resta,resta,element,15);//erosiono

    //Puede que algun contorno no deseado aún permanezca en la imagen binaria. Como aplico las mismas transformaciones morfológicas a las dos imágenes binarias 
	//tendré el mismo defecto en las dos imagenes, así que  obtengo una imagen sólo los defectos, y después resto los defectos a las dos imágenes.


IplImage * temp3= cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);
IplImage * temp4= cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);
IplImage * Im_defectos_comunes= cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);
IplImage * Im_bolas_azules= cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);
IplImage * Im_bolas_rojas= cvCreateImage(cvGetSize(Imagen_umbr),IPL_DEPTH_8U,1);


cvThreshold(temp2,temp3,umbral2,255,CV_THRESH_BINARY_INV);//invierto las bolas rojas

cvThreshold(resta,temp4,umbral2,255,CV_THRESH_BINARY_INV);//invierto las bolas azules

cvAnd(temp3,temp4,Im_defectos_comunes,NULL);//multiplico las dos imagenes, la imagen que obtengo solo aparecen los defectos comunes

cvAbsDiff (temp2,Im_defectos_comunes,Im_bolas_azules);//resto los defectos a las bolas azules

cvAbsDiff (resta, Im_defectos_comunes ,Im_bolas_rojas);//resto los defectos a las bolas rojas

//Ya tengo una imagen binaria sólo con las bolas azules y otra sólo con las rojas.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//CALCULAR HISTOGRAMA DE LA IMAGEN G






//Nueva imagen para dibujar el histograma
IplImage *histImage;
//Variables para el histograma
int hist_size=256;
int NivelGris;
float NumPixels;
//Estructura histograma para guardar la informacion
CvHistogram *hist;




//Nueva imagen para dibujar el histograma
histImage = cvCreateImage(cvSize(256,256), 8, 1);
//Estructura histograma para guardar la informacion
hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY,NULL, 1);
//calcular el histograma. Lo hago con la imagenG, ya que hay más contraste que en la imagen en escala de grises, pero también funcionaria con la imagen de escala de grises
cvCalcHist(&ImagenG,hist,0,NULL);
cvSetZero(histImage);

long Histograma[256];

//dibujo el histograma
for(NivelGris=0;NivelGris<hist_size;++NivelGris)
{
NumPixels=cvQueryHistValue_1D(hist,NivelGris)/15;
cvLine(histImage,cvPoint(NivelGris,256),cvPoint(NivelGris,256-NumPixels),CV_RGB(255,255,255),1,8,0);

Histograma[NivelGris]=NumPixels;//meto en un array el numero de pixels para cada nivel de gris
}

cvReleaseHist(&hist);
cvSaveImage("Histograma.jpg",histImage,0);
      
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//UMBRALIZACIÓN DE LA IMAGEN G


IplImage *imagen_bin;
CvMemStorage *Memoria;
CvSeq *Contorno, *Primer_Contorno;
int Nc;
//imagen=cvLoadImage("herramientas.tif",CV_LOAD_IMAGE_GRAYSCALE);
imagen_bin=cvCreateImage(cvGetSize(ImagenG),8,1);
//imagen_color=cvCreateImage(cvGetSize(ImagenG),8,3);

//umbralizar la ImagenG
int umbral;


umbral=MinMax(Histograma);

//Para algunas imagenes, debido a que tienen mas iluminacion o se introducen otros objetos como la mano, en el histograma las gausianas se juntan mucho o solo aparece
//una. En este caso la función MinMAx() calcula  un umbral muy alto y hace que no se detecten los contornos de algunas bolas, asi que establezco un umbral máximo

if(umbral>100)
{
	umbral=100;
}


cvLine(histImage,cvPoint(umbral,256),cvPoint(umbral,0),CV_RGB(255,255,255),1,8,0);//uDibujo el umbral en el histograma


cvThreshold(ImagenG,imagen_bin,umbral,255,CV_THRESH_BINARY_INV);//Binarizo la imagen G

cvMorphologyEx(imagen_bin,imagen_bin,imagen_bin, NULL,CV_MOP_CLOSE,6);//Alplico cierre para eliminar los cambios de contraste en el interior de las bolas 
//debido al reflejo al reflejo de la luz

	
 



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------


// CÁLCULO DE CONTORNOS, ÁREAS, PERÍMETROS, CAJAS Y CENTROS DE CAJA EN LA IMAGEN G.

 IplConvKernel* element_2 = 0;
     const int element_shape_2 =CV_SHAPE_ELLIPSE;
	 int pos_2=1;
  
     element_2= cvCreateStructuringElementEx(pos_2*2+1,pos_2*2+1,pos_2,pos_2, element_shape_2,0);


Memoria=cvCreateMemStorage();
bool k=FALSE;
int n=0;
bool pelotas_juntas=FALSE;
int i;
double *perimetro;
double *area;
CvBox2D *BoundBox;

 CvPoint *centro;

int bolas_rotas_azules=0;
int bolas_rotas_rojas=0;

CvScalar s3;






     Nc=cvFindContours(imagen_bin,Memoria,&Primer_Contorno,sizeof(CvContour),CV_RETR_EXTERNAL);
   


     perimetro=(double*)malloc(Nc*sizeof(double));
     area=(double*)malloc(Nc*sizeof(double));
     BoundBox=(CvBox2D*)malloc(Nc*sizeof(CvBox2D));
	 centro=(CvPoint*)malloc(Nc*sizeof(CvPoint));
	
	
     for(i=0,Contorno=Primer_Contorno;Contorno!=NULL;Contorno=Contorno->h_next,++i)
     {
	      area[i]=cvContourArea(Contorno,CV_WHOLE_SEQ);
	      perimetro[i]=cvArcLength(Contorno,CV_WHOLE_SEQ,1);
	      BoundBox[i]=cvMinAreaRect2(Contorno,NULL);
		  

     }

	  for(i=0;i<Nc;++i)
      {

		  centro[i] = cvPoint( BoundBox[i].center.x,BoundBox[i].center.y);
      }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------	  

//DETECTAR BOLAS ROTAS	  
	  
	  
	  
	  
IplImage * inv_bolas_azules, *inv_bolas_rojas;
CvMemStorage *storage_2;
CvMemStorage *storage_3;
CvSeq *Contorno_2, *Primer_Contorno_2;
CvSeq *Contorno_3, *Primer_Contorno_3;

int Nc_2;
int Nc_3;
double *area_2;
double *area_3;
CvBox2D *BoundBox_2;
CvBox2D *BoundBox_3;
CvPoint *centro_2;
CvPoint *centro_3;



inv_bolas_azules=cvCreateImage(cvGetSize(Im_bolas_azules),8,1);

inv_bolas_rojas=cvCreateImage(cvGetSize(Im_bolas_rojas),8,1);

cvThreshold(Im_bolas_azules,inv_bolas_azules,128,255,CV_THRESH_BINARY_INV);
cvThreshold(Im_bolas_rojas,inv_bolas_rojas,128,255,CV_THRESH_BINARY_INV);

storage_2=cvCreateMemStorage();
storage_3=cvCreateMemStorage();


//detecto las bolas rotas azules
Nc_2=cvFindContours(inv_bolas_azules,storage_2,&Primer_Contorno_2,sizeof(CvContour),CV_RETR_EXTERNAL); //Encuentro cotornos en la imagen binaria donde sólo aparecen 
                                                                                                       //las bolas azules



     
     area_2=(double*)malloc(Nc_2*sizeof(double));//tamaño del vector area
     
     BoundBox_2=(CvBox2D*)malloc(Nc_2*sizeof(CvBox2D));//tamaño  del vector BoundBox_2
	 
	 centro_2=(CvPoint*)malloc(Nc_2*sizeof(CvPoint));//tamaño del vector centro_2
	 
	

     for(i=0,Contorno_2=Primer_Contorno_2;Contorno_2!=NULL;Contorno_2=Contorno_2->h_next,++i)
     {
	      area_2[i]=cvContourArea(Contorno_2,CV_WHOLE_SEQ);//Hallo el area de cada contorno
	      
	      
	      BoundBox_2[i]=cvMinAreaRect2(Contorno_2,NULL);//Hallo las caja de cada contorno
		  
		  
		  
	 }

	  for(i=0;i<Nc_2;++i)
      {

		  centro_2[i] = cvPoint( BoundBox[i].center.x,BoundBox[i].center.y);// Hallo el centro de cada contorno
      }

	 
	  
	  
	 
	  
	 //Para cada contorno, si su area es menor que 2500, es que se trata de una bola rota


	  for(i=0;i<Nc_2;++i)
	  {
		  if(area_2[i]<2500)
		  {
			  bolas_rotas_azules++;
			  DibujarBox2D(im,BoundBox_2[i]);
			  printf("Bola  rota azul en:\n x=%d\n y=%d\n",centro[i].y,centro[i].x);
		  }
	  }


	//Detecto las bolas rotas rojas

	// Es el mismo procedimiento que para detectar las bolas rotas azules, pero encontrando contornos en la imagen binaria donde solo aparecen las bolas rojas
	  Nc_3=cvFindContours(inv_bolas_rojas,storage_3,&Primer_Contorno_3,sizeof(CvContour),CV_RETR_EXTERNAL);



     
     area_3=(double*)malloc(Nc_3*sizeof(double));
     
     BoundBox_3=(CvBox2D*)malloc(Nc_3*sizeof(CvBox2D));
	 
	  centro_3=(CvPoint*)malloc(Nc*sizeof(CvPoint));
	 
	 
	

     for(i=0,Contorno_3=Primer_Contorno_3;Contorno_3!=NULL;Contorno_3=Contorno_3->h_next,++i)
     {
	      area_3[i]=cvContourArea(Contorno_3,CV_WHOLE_SEQ);
	      
	      
	      BoundBox_3[i]=cvMinAreaRect2(Contorno_3,NULL);
		  
		  
		  
	 }

	  for(i=0;i<Nc_3;++i)
      {

		  centro_3[i] = cvPoint( BoundBox[i].center.x,BoundBox[i].center.y);
      }
	  
	  
	  
	 
	  for(i=0;i<Nc_3;++i)
	  {
		  if(area_3[i]<2000)
		  {
			  bolas_rotas_rojas++;
			  DibujarBox2D(im,BoundBox_3[i]);
			  printf("Bola  rota roja en:\n x=%d\n y=%d\n",centro[i].y,centro[i].x);
		  }
	  }

	  
	  
	  
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//CASO DE LAS BOLAS JUNTAS

// En el caso de que haya dos o más bolas juntas, el programa encuentra un contorno con el área de todas las bolas que están juntas. Para solucionar este problema
//utilizo el perímetro de los contornos. Elijo un valor umbral para el perímetro en el que me aseguro que se han separado todas las bolas. Así, si existe un perímetro 
//mayor al umbral, erosiono la imagen hasta que todos los perímetros sean menores que ese umbral. 
	 
// Para detectar si hay bolas juntas, compruebo si existe algún controno que tenga el área mayor que el de una bola . 	 
	 for(i=0;i<Nc;++i)
	 {
		 if(area[i]>4000)//si existe el área de un contorno mayor al área de una bola
		 {
			 k=TRUE;
			 pelotas_juntas=TRUE;
		 }

		 
	 }

while(k==TRUE)// Se mete en este bucle si ha encontrado algun área mayor que el de una bola
{

		 k=FALSE;
		 Nc=cvFindContours(imagen_bin,Memoria,&Primer_Contorno,sizeof(CvContour),CV_RETR_EXTERNAL);
  


     perimetro=(double*)malloc(Nc*sizeof(double));
     area=(double*)malloc(Nc*sizeof(double));
     
     BoundBox=(CvBox2D*)malloc(Nc*sizeof(CvBox2D));
	
	 centro=(CvPoint*)malloc(Nc*sizeof(CvPoint));
	
	 

     for(i=0,Contorno=Primer_Contorno;Contorno!=NULL;Contorno=Contorno->h_next,++i)
     {
	      area[i]=cvContourArea(Contorno,CV_WHOLE_SEQ);
	      perimetro[i]=cvArcLength(Contorno,CV_WHOLE_SEQ,1);
	     
	      BoundBox[i]=cvMinAreaRect2(Contorno,NULL);
		  
		 
		 
     }

	 for(i=0;i<Nc;++i)
      {
	       centro[i] = cvPoint( BoundBox[i].center.x,BoundBox[i].center.y);
      }


	

	 for(i=0;i<Nc;++i)
	 {
		 

		 if(perimetro[i]>100)
		 {
			 k=TRUE;
			 cvErode(imagen_bin,imagen_bin,element_2,1);
		 }

		
	 }



}



    

//------------------------------------------------------------------------------------------------------------------------------------------------------------


//CONOCER EL NÚMERO DE BOLAS DE CADA COLOR  Y SUS RESPECTIVAS POSICIONES




int bolas_azules=0;
int bolas_rojas=0;

int mano=0;
double radio=0.0;
CvScalar s;
CvScalar s2;


//Diferenciar bolas en el caso de que no haya bolas juntas
if( pelotas_juntas==FALSE)
{

    //Bolas azules
    for(i=0;i<Nc;++i)//bucle para todods los contornos
       {

           s=cvGet2D(Im_bolas_azules,centro[i].y,centro[i].x);//Cojo los centros y compruebo de qué color es el pixel en la imagen de bolas azules
		   if(s.val[0]==0)// si es 0,es que puede haber una bola azul o una bola rota azul
		     {
		          if(area[i]>2000 && area[i]<4000)//bola azul 
		            {
			             bolas_azules++;


			             radio=sqrt(area[i]/3.14);

			             cvCircle(
                                  im,
                                  centro[i],
                                  cvRound( radio ),
                                  CV_RGB(0x00,0xff,0xff));

			                      printf("Bola azul en:\n x=%d\n y=%d\n",centro[i].y,centro[i].x);
		             }
		     }
}


			   


	//Bolas rojas
     for(i=0;i<Nc;++i)//bucle para todos los contornos
       {
   
	       s2=cvGet2D(Im_bolas_rojas,centro[i].y,centro[i].x);//Cojo el centro y compruebo de qué color es el pixel en la imagen con bolas rojas

	       if(s2.val[0]==0)// si es 0,es que puede haber bola roja o bola rota roja
		     {
		         if(area[i]>2000 && area[i]<4000)//bola roja
		           {
			            bolas_rojas++;

			            radio=sqrt(area[i]/3.14);

			            cvCircle(
                                  im,
                                  centro[i],
                                  cvRound( radio ),
                                  CV_RGB(0xff,0x00,0x00));

			                      printf("Bola roja en:\n x=%d\n y=%d\n",centro[i].y,centro[i].x);
		           }
		   
		   
		     }
        }


		



}

if( pelotas_juntas==TRUE)
{
    float radio=30;//Como en el caso de qhe haya bolas juntas erosiono la imagen hasta separlas, no tengo las áreas reales de las bolas, así que
	              //estipulo un radio aproximado .


	//Bolas azules
    for(i=0;i<Nc;++i)
       {

          s=cvGet2D(Im_bolas_azules,centro[i].y,centro[i].x);//Cojo los centros y compruebo de qué color es el pixel en la imagen con bolas azules
		  if(s.val[0]==0)// si es 0,es que hay bola azul. En este caso no existe la posibilidad de que haya bolas rotas porque al erosionar solo permanecen los contornos
			             //con un perímetro mayor al de una bola. El perímetro de una bola rota siempre será menor
		   {
		   

			   cvCircle(
                        im,
                        centro[i],
                        cvRound( radio ),
                        CV_RGB(0x00,0xff,0xff));

			   bolas_azules++;

			   printf("Bola azul en:\n x=%d\n y=%d\n",centro[i].y,centro[i].x);





		   }
		   
		   
		

	
       }






	//Bolas rojas	
    for(i=0;i<Nc;++i)//bucle para todos los contornos
       {
   
	       s2=cvGet2D(Im_bolas_rojas,centro[i].y,centro[i].x);//Cojo el centro y compruebo de qué color es el pixel en la imagen con bolas rojas

	       if(s2.val[0]==0)// si es 0,es que hay una bola roja
		     {
		   
			     cvCircle(
                          im,
                          centro[i],
                          cvRound( radio ),
                          CV_RGB(0xff,0x00,0x00));

			     bolas_rojas++;

			     printf("Bola roja en:\n x=%d\n y=%d\n",centro[i].y,centro[i].x);
		     }
		   
		   
		
	   }

}



printf("bolas azules:%d\n",bolas_azules);
printf("bolas rotas azules:%d\n", bolas_rotas_azules);
printf("bolas rojas:%d\n",bolas_rojas);
printf("bolas rotas rojas:%d\n\n",bolas_rotas_rojas);


printf("ORDENAR AL ROBOT\n\n\n");
if(bolas_rotas_azules>0)
{
	printf("METER BOLAS AZULES DEFECTUOSAS EN CAJA DE BOLAS AZULES DEFECTUOSAS\n\n");
}

if(bolas_rotas_rojas>0)
{
	printf("METER BOLAS ROJAS DEFECTUOSAS EN CAJA DE BOLAS ROJAS DEFECTUOSAS\n\n");
}

if(bolas_azules>0 || bolas_rojas>0)
{
	printf("EMPAQUETAR BOLAS\n\n");
}



//----------------------------------------------------------------------------------------------------------------------------------------------------------------------





cvWaitKey(0);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//PANTALLA

cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
cvShowImage("Original", im );

//cvNamedWindow("imagen_bin", CV_WINDOW_AUTOSIZE);
//cvShowImage("imagen_bin", imagen_bin );

//Mostrar el plano de color rojo, verde y azul

//cvNamedWindow("R", CV_WINDOW_AUTOSIZE);
//cvShowImage("R",ImagenR);

//cvNamedWindow("G", CV_WINDOW_AUTOSIZE);
//cvShowImage("G",inv_bolas_azules);

//cvNamedWindow("B", CV_WINDOW_AUTOSIZE);
//cvShowImage("B",inv_bolas_rojas);

cvNamedWindow("bolas_azules", CV_WINDOW_AUTOSIZE);
cvShowImage("bolas_azules",Im_bolas_azules);

cvNamedWindow("bolas_rojas", CV_WINDOW_AUTOSIZE);
cvShowImage("bolas_rojas",Im_bolas_rojas);

//Mostrar la imagen

cvNamedWindow("Histograma de G", CV_WINDOW_AUTOSIZE);
cvShowImage("Histograma de G", histImage );

cvWaitKey(0);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

//LIBERAR MEMORIA
cvDestroyAllWindows();

cvReleaseImage(&ImagenR);
cvReleaseImage(&ImagenG);
cvReleaseImage(&ImagenB);
cvReleaseImage(&imagen_bin);
cvReleaseImage(&histImage);
cvReleaseImage(&im);
cvReleaseImage(&Imagen_RGB);
cvReleaseImage(&Imagen_umbr);
cvReleaseImage(&Imagen_umbr_2);
cvReleaseImage(&ImagenHSV);
cvReleaseImage(&ImagenH);
cvReleaseImage(&ImagenS);
cvReleaseImage(&ImagenV);
cvReleaseImage(&temp);
cvReleaseImage(&temp2);
cvReleaseImage(&temp3);
cvReleaseImage(&temp4);
cvReleaseImage(&Im_defectos_comunes);
cvReleaseImage(&Im_bolas_azules);
cvReleaseImage(&Im_bolas_rojas);
cvReleaseImage(&inv_bolas_rojas);
cvReleaseImage(&inv_bolas_azules);









}while(salir==FALSE);

return 0;


}
//FIN DEL MAIN
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//funcion que calcula el umbral
int MinMax(long *Histograma)
{
	int i, maximo1,maximo2,minimo;
	maximo1=0;
	long HistogramaAux[256];

	for(i=1;i<256;++i)
	{
		if(Histograma[maximo1]<Histograma[i])
		{
			maximo1=i;
		}
	}

	for(i=0;i<256;++i)
	{
		HistogramaAux[i]=Histograma[i]*abs(i-maximo1);
	}


	maximo2=0;


	for(i=1;i<256;++i)
	{
		if(HistogramaAux[maximo2]<HistogramaAux[i])
		{
			maximo2=i;
		}
	}
	


	//printf("maximo1 %d  maximo2 %d\n",maximo1,maximo2);

	if(maximo1<maximo2)
	{
		minimo=maximo1;

		for(i=minimo+1;i<maximo2;++i)
		{
			if(Histograma[i]<Histograma[minimo])
			{
				minimo=i;
			}
		}
	}




	

	else
	{
		minimo=maximo2;

		for(i=minimo+1;i<maximo1;++i)
		{
			if(Histograma[i]<Histograma[minimo])
			{
				minimo=i;
			}
		}
	}

	//printf("minimo %d\n",minimo);
		return (minimo);
}




//funcion que dibuja rectangulos


void DibujarBox2D(IplImage *imagen,CvBox2D BoundBox)
{

	int x0,y0,x1,y1,x,y;

	float angulo;

	angulo=(BoundBox.angle)*3.14/180;
//------------------------------------------------------------------------------------------------
	x=-BoundBox.size.width/2;
	y=BoundBox.size.height/2;

	x0=BoundBox.center.x+x*cos(angulo)-y*sin(angulo);
	y0=BoundBox.center.y+x*sin(angulo)+y*cos(angulo);

	x=BoundBox.size.width/2+2;
	y=BoundBox.size.height/2+2;

	x1=BoundBox.center.x+x*cos(angulo)-y*sin(angulo);
	y1=BoundBox.center.y+x*sin(angulo)+y*cos(angulo);


	cvDrawLine(imagen,cvPoint(x0,y0),cvPoint(x1,y1),CV_RGB(0xff,0xff,0xff),1,8,0);

	//--------------------------------------------------------------------------------------------

	x0=x1;
	y0=y1;

	x=BoundBox.size.width/2;
	y=-BoundBox.size.height/2;

	x1=BoundBox.center.x+x*cos(angulo)-y*sin(angulo);
	y1=BoundBox.center.y+x*sin(angulo)+y*cos(angulo);

	cvDrawLine(imagen,cvPoint(x0,y0),cvPoint(x1,y1),CV_RGB(0xff,0xff,0xff),1,8,0);
//------------------------------------------------------------------------------------------------------
	x0=x1;
	y0=y1;

	x=-BoundBox.size.width/2;
	y=-BoundBox.size.height/2;


	x1=BoundBox.center.x+x*cos(angulo)-y*sin(angulo);
	y1=BoundBox.center.y+x*sin(angulo)+y*cos(angulo);

	cvDrawLine(imagen,cvPoint(x0,y0),cvPoint(x1,y1),CV_RGB(0xff,0xff,0xff),1,8,0);
//-----------------------------------------------------------------------------------------------
	x0=x1;
	y0=y1;

	x=-BoundBox.size.width/2;
	y=BoundBox.size.height/2;

	x1=BoundBox.center.x+x*cos(angulo)-y*sin(angulo);
	y1=BoundBox.center.y+x*sin(angulo)+y*cos(angulo);

	cvDrawLine(imagen,cvPoint(x0,y0),cvPoint(x1,y1),CV_RGB(0xff,0xff,0xff),1,8,0);
//-------------------------------------------------------------------------------------------
}


	















