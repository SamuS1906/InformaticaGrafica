//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //cambiado por sólido
//glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //cambiado por sólido
//glLineWidth(grosor);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	if(i%2==0) glColor3f(r1,g1,b1);
	else glColor3f(r2,g2,b2);
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();

}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r1, g1, b1, grosor);break;
	case EDGES:draw_aristas(r1, g1, b1, grosor);break;
	case SOLID_CHESS:draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);break;
	case SOLID:draw_solido(r1, g1, b1);break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
vertices.resize(8); 
vertices[0].x=0;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=0;
vertices[3].x=0;vertices[3].y=0;vertices[3].z=0; // El vertice 3 está en el (0,0,0)
vertices[4].x=0;vertices[4].y=tam;vertices[4].z=tam;
vertices[5].x=tam;vertices[5].y=tam;vertices[5].z=tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=0;
vertices[7].x=0;vertices[7].y=tam;vertices[7].z=0;
// matriz de triangulos

caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4; // la cara 0 esta formada por los vertices 0 1 y 4
caras[1]._0=1;caras[1]._1=5;caras[1]._2=4;
caras[2]._0=1;caras[2]._1=2;caras[2]._2=5;
caras[3]._0=2;caras[3]._1=6;caras[3]._2=5;
caras[4]._0=2;caras[4]._1=3;caras[4]._2=6; 
caras[5]._0=3;caras[5]._1=7;caras[5]._2=6; 
caras[6]._0=0;caras[6]._1=3;caras[6]._2=7; 
caras[7]._0=0;caras[7]._1=4;caras[7]._2=7;
caras[8]._0=4;caras[8]._1=5;caras[8]._2=6;
caras[9]._0=4;caras[9]._1=6;caras[9]._2=7;
caras[10]._0=3;caras[10]._1=1;caras[10]._2=0; 
caras[11]._0=3;caras[11]._1=2;caras[11]._2=1; 

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
}



//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



int _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car, i;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);

for(i=0; i<n_ver; i++){
  vertices[i].x = ver_ply[3*i];
  vertices[i].y = ver_ply[3*i+1];
  vertices[i].z = ver_ply[3*i+2];
}

caras.resize(n_car);

for(i=0; i<n_car; i++){
  caras[i]._0 = car_ply[3*i];
  caras[i]._1= car_ply[3*i+1];
  caras[i]._2 = car_ply[3*i+2];
}

return(0);
}

//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num)
{
int i,j, c;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

num_aux=perfil.size();
vertices.resize(num_aux*num+2); //OJO +2 para las tapas

//Permitir que se pueda meter el vector de puntos de la generatriz en cualquier sentido
//si se introduce de arriba a abajo, lo cambiamos de orden para que sea de abajo a arriba.
if(perfil[num_aux].y < perfil[0].y) {
  //lo que hacemos es cambiar de orden el perfil, para que sea de abajo a arriba
  
  j=num_aux-1;
  for(i=0; i<num_aux/2; i++){
    vertice_aux = perfil[i];
    perfil[i]=perfil[j];
    perfil[j]=vertice_aux;
    j--;
  }
}

// tratamiento de los vértices
for (j=0;j<num;j++)
  {for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras 

caras.resize(2*(num_aux-1)*num+2*num);
c=0;
for(j=0;j<num;j++){
  for(i=0;i<num_aux-1;i++){
      cara_aux._0=i+((j+1)%num)*num_aux;
			cara_aux._1=i+1+((j+1)%num)*num_aux;
			cara_aux._2=i+1+j*num_aux;
			caras.push_back(cara_aux);

			cara_aux._0 = i+1+j*num_aux;
			cara_aux._1 = i+j*num_aux;
			cara_aux._2 = i+((j+1)%num)*num_aux;
			caras.push_back(cara_aux);
  }
}

     
 // tapa inferior
if (fabs(perfil[0].x)>0.0)
  {
      vertices[num_aux*num].x=0.0; 
			vertices[num_aux*num].y=perfil[0].y; 
			vertices[num_aux*num].z=0.0;

		for (j=0;j<num;j++){
			caras[c]._0=num_aux*num;
			caras[c]._1=j*num_aux;
			caras[c]._2=((j+1)%num)*num_aux;
			c=c+1;
		}
  }
 
 // tapa superior
 if (fabs(perfil[num_aux-1].x)>0.0)
  {
    vertices[num_aux*num+1].x=0.0; 
		vertices[num_aux*num+1].y=perfil[num_aux-1].y;
		vertices[num_aux*num+1].z=0.0;

		for (j=0;j<num;j++){	
			caras[c]._0=num_aux*num+1;
			caras[c]._1=j*num_aux+num_aux-1;
			caras[c]._2=((j+1)%num)*num_aux+num_aux-1;

			c=c+1;
		}
  }


}


// //************************************************************************
// esfera
//************************************************************************

_esfera::_esfera()
{

}

void _esfera::parametros(int n,int m, double r)
{

	//n numero de puntos del perfil
	//m numeros caras de la esfera
	//r = radio = sqrt(perfil[0].x*perfil[0].x+perfil[0].y*perfil[0].y);

	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux; 
	num = m;


	for(i=1; i<n; i++){
		vertice_aux.x = r*cos(M_PI*i/n-M_PI/2.0);
		vertice_aux.y= r*sin(M_PI*i/n-M_PI/2.0);
		vertice_aux.z=0;
		perfil.push_back(vertice_aux);
	}
	

	//perfil lo generas tu con el radio
	num_aux=perfil.size();
	vertices.resize(num_aux*num+2);


	
	for (j=0;j<num;j++){
		for (i=0;i<num_aux;i++){
			vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
							perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
			vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
							perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
			vertice_aux.y=perfil[i].y;
			vertices[i+j*num_aux]=vertice_aux;
		}
	}


	caras.resize((num_aux-1)*2*num+2*num);

	int c=0;

	for (j=0;j<num;j++){
		for(i=0; i<num_aux-1;i++){
			cara_aux._0 = i+1+j*num_aux;
			cara_aux._1 = i+1+((j+1)%num)*num_aux;
			cara_aux._2 = i+((j+1)%num)*num_aux;
			caras.push_back(cara_aux);

			cara_aux._0 = i+1+j*num_aux;
			cara_aux._1 = i+j*num_aux;
			cara_aux._2 = i+((j+1)%num)*num_aux;
			caras.push_back(cara_aux);
		}
	}



	// tapa inferior
	if (fabs(perfil[0].x)>0.0){

		vertices[num_aux*num].x=0.0; 
		vertices[num_aux*num].y=-r; 
		vertices[num_aux*num].z=0.0;

	for (j=0;j<num;j++){
			caras[c]._0=num_aux*num;
			caras[c]._1=j*num_aux;
			caras[c]._2=((j+1)%num)*num_aux;
			c=c+1;
		}
	}

	// tapa superior
	if (fabs(perfil[num_aux-1].x)>0.0){

	vertices[num_aux*num+1].x=0.0; 
	vertices[num_aux*num+1].y=r;
	vertices[num_aux*num+1].z=0.0;

		for (j=0;j<num;j++){

			caras[c]._0=num_aux*num+1;
			caras[c]._1=j*num_aux+num_aux-1;
			caras[c]._2=((j+1)%num)*num_aux+num_aux-1;

			c=c+1;
		}

	}
}

//************************************************************************
// cono
//************************************************************************

_cono::_cono()
{

}

void _cono::parametros(vector<_vertex3f> perfil, int num, double altura)
{

	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;
	
	h = altura;

	//num numero de lados
	//num_aux es el numero de puntos del perfil y en el cono es 1
	num_aux=1;
	vertices.resize(num_aux*num+2);


	for (j=0;j<num;j++)
	{
		for (i=0;i<num_aux;i++){
			vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
							perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
			vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
							perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
			vertice_aux.y=perfil[i].y;
			vertices[i+j*num_aux]=vertice_aux;
		}
	}

	

	// tratamiento de las caras 

	caras.resize((num_aux-1)*2*num+2*num);


	int c=0;
	// tapa inferior
	if (fabs(perfil[0].x)>0.0){

			vertices[num_aux*num].x=0.0; 
			vertices[num_aux*num].y=perfil[0].y; 
			vertices[num_aux*num].z=0.0;


		for (j=0;j<num;j++){
			caras[c]._0=num_aux*num;
			caras[c]._1=j*num_aux;
			caras[c]._2=((j+1)%num)*num_aux;
			c=c+1;
		}
	}

	// tapa superior
	if (fabs(perfil[num_aux-1].x)>0.0)
	{
			vertices[num_aux*num+1].x=0.0; 
			vertices[num_aux*num+1].y=h;
			vertices[num_aux*num+1].z=0.0;

		for (j=0;j<num;j++){	
			caras[c]._0=num_aux*num+1;
			caras[c]._1=j*num_aux+num_aux-1;
			caras[c]._2=((j+1)%num)*num_aux+num_aux-1;
			c=c+1;
		}
	}
 
}


//************************************************************************
// cilindro
//************************************************************************

_cilindro::_cilindro()
{

}

void _cilindro::parametros(vector<_vertex3f> perfil, int num)
{
	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

	num_aux=perfil.size();
	vertices.resize(num_aux*num+2);

	//Permitir que se pueda meter el vector de puntos de la generatriz en cualquier sentido
	//si se introduce de arriba a abajo, lo cambiamos de orden para que sea de abajo a arriba.
	j=num_aux-1;
	for(i=0; i<num_aux/2; i++){
		vertice_aux = perfil[i];
		perfil[i]=perfil[j];
		perfil[j]=vertice_aux;
		j--;
	}


	for (j=0;j<num;j++){
		for (i=0;i<num_aux;i++){
		vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
						perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
		vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
						perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
		vertice_aux.y=perfil[i].y;
		vertices[i+j*num_aux]=vertice_aux;
		}
	}

	caras.resize((num_aux-1)*2*num+2*num);

	int c=0;
	for (j=0;j<num-1;j++){
		caras[c]._0=j*num_aux;
		caras[c]._1=j*num_aux+1;
		caras[c]._2=(j+1)*num_aux+1;
		c=c+1; 

		caras[c]._0=(j+1)*num_aux+1;	
		caras[c]._1=(j+1)*num_aux;	
		caras[c]._2=j*num_aux;		
		c=c+1;
	}

	//cierre de la ultima cara del ultimo lado del cilindro

		caras[c]._0=num_aux*num -2; 
		caras[c]._1=num_aux*num -1; 
		caras[c]._2=1;

		c=c+1; 
		caras[c]._0=1; 
		caras[c]._1=0 ;
		caras[c]._2=num_aux*num-2;
	
		c=c+1;

	// tapa inferior
	if (fabs(perfil[0].x)>0.0){
		vertices[num_aux*num].x=0.0; 
		vertices[num_aux*num].y=perfil[0].y; 
		vertices[num_aux*num].z=0.0;

		for (j=0;j<num-1;j++){
			caras[c]._0=num_aux*num;
			caras[c]._1=j*num_aux;
			caras[c]._2=(j+1)*num_aux;

			c=c+1;
		}

		//enganchar la ultima cara del ultimo lado de la tapa inferior
		caras[c]._0=num_aux*num;
		caras[c]._1= 0;
		caras[c]._2=num_aux*num-2;
		c=c+1;
	}

	// tapa superior
	if (fabs(perfil[num_aux-1].x)>0.0){

		vertices[num_aux*num+1].x=0.0; 
		vertices[num_aux*num+1].y=perfil[num_aux-1].y; 
		vertices[num_aux*num+1].z=0.0;

		for (j=0;j<num-1;j++){
			caras[c]._0=num_aux*num+1; 
			caras[c]._1=j*2+1;
			caras[c]._2=(j+1)*2+1;

			c=c+1;
		}

		caras[c]._0=num_aux*num+1;
		caras[c]._1=1; 
		caras[c]._2=num_aux*num-1; 
	}
		
}