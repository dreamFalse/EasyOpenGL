#ifndef MODEL_H
#define MODEL_H 

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.h"
#include "shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

unsigned int TextureFromFile(const char* path, const string &directory, bool gamma=false);

class Model
{
public:
    // model data
    vector<Texture> textures_loaded;
    vector<Mesh>    meshes;
    string directory;
    bool gammaCorrection;

    // constructor, expects a filepath to a 3D model.
    Model(string const& path, bool gamma=false) : gammaCorrection(gamma)
    {
        loadModel(path);
    }

    // draws the model, and thus all its meshes
    void Draw(Shader &shader)
    {
        for(unsigned int i=0; i<meshes.size(); i++)
            meshes[i].Draw(shader);
    }
private:
    // loads a model with supported ASSIMP extensions from file and stores the resulting mesh in the meshes vector
    void loadModel(string const &path)
    {
        // read file via ASSIMP
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
        // check for errors
        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            cout << "ERROR::ASSIMP::" <<importer.GetErrorString()<<endl;
            return; 
        }
        // retreive the directory path of the filepath
        directory = path.substr(0, path.find_last_of('/'));
        // process ASSIMP's root  node recursively
        processNode(scene->mRootNode, scene);
    }
    void processNode(aiNode* node, const aiScene *scene)
    {
        
    }
};


#endif