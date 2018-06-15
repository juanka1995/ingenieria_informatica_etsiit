#include "objetoPLY.h"

ObjetoPLY::ObjetoPLY(const std::string &ply_file){

    _file_ply File_ply;

    vector<_vertex3f> Vertices;
    vector<_vertex3i> Triangles;

    if (File_ply.open(ply_file)){
        File_ply.read(Vertices,Triangles,isFileReaded);

        if(isFileReaded){
            numVertices = Vertices.size();
            numCaras = Triangles.size();
            
            // Vertices
            for(unsigned int i = 0; i < numVertices; i++){
                vertices.push_back(Vertice(Vertices[i].x,Vertices[i].y,Vertices[i].z));
            }
    
            // Triangulos
            for(unsigned int i = 0; i < numCaras; i++){
                caras.push_back(Triangulo(Triangles[i]._0,Triangles[i]._1,Triangles[i]._2));
            }
    
            // Color
            for(unsigned int i = 0 ; i < numVertices ; i++){
                this->color.push_back(Color(defaultColor.r, defaultColor.g, defaultColor.b));
            }
        }
    }
}

bool ObjetoPLY::getIsFileReaded() const{
    return isFileReaded;
}

void ObjetoPLY::setIsFileReaded(bool newValue){
    isFileReaded = newValue;
}