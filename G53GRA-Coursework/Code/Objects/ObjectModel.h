#pragma once
#include <vector>

class ObjectModel
{
public:
	void SetVertices(std::vector<float*> vertices);
	void SetUVCoordinates(std::vector<float*> uvCoordinates);
	void SetNormals(std::vector<float*> normals);
	void SetFaces(std::vector<int**> faces, std::vector<int> faceMaterials);

	void Render() const;
private:
	float** Vertices;
	float** UVCoordinates;
	float** Normals;
	int*** Faces;
	int* FaceMaterials;

	int NumVertices;
	int NumUVCoordinates;
	int NumNormals;
	int NumFaces;

	static const int FACES_VERTEX_INDEX = 0;
	static const int FACES_MATCOORD_INDEX = 1;
	static const int FACES_NORMAL_INDEX = 2;

	static void beginRenderingSetOfFaces(int textureId);
	void renderFace(int** face) const;
};
