#pragma once
#include "MeshTypes.h"

namespace ProtoEngine::Graphics
{
	class MeshBuilder
	{
	public:
		//cube
		static MeshPC CreateCubePC(float size, const Color& color);
		static MeshPC CreateCubePC(float size);
		//static MeshPC CreateCubePX(float size);

		static MeshPC CreateRectanglePC(float width, float height, float depth);

		// plane
		static MeshPC CreatePlanePC(int numRows, int numColumns, float spacing, bool horizontal = true);
		static MeshPX CreatePlanePX(int numRows, int numColumns, float spacing, bool horizontal = true);
		
		// Cylinder
		static MeshPC CreateCylinderPC(int slices, int rings);

		// sphere
		static MeshPC CreateSpherePC(int slices, int rings, float radius);
		static MeshPX CreateSpherePX(int slices, int rings, float radius);

		// Pyramid.
		static MeshPC CreatePyramidPC(int sides, float radius, float height);

		// skybox
		static MeshPX CreateSkySpherePX(int slices, int rings, float radius);


	};
}