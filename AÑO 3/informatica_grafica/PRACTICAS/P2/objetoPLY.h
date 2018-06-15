#ifndef _OBJETO_PLY_H
#define _OBJETO_PLY_H

#include "objeto3d.h"
#include "file_ply_stl.h"


class ObjetoPLY : public Object3D{
protected:
    bool isFileReaded;    
public:
    ObjetoPLY(){};
    ObjetoPLY(const std::string &ply_file);
    bool getIsFileReaded() const;
    void setIsFileReaded(bool newValue);   
};

#endif