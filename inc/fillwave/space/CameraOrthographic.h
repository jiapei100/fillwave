/*
 * CameraOrthographic.h
 *
 *  Created on: Dec 21, 2014
 *      Author: Filip Wasil
 *
 * Copyright (c) 2016, Filip Wasil
 * All rights reserved.
 *
 * Fillwave C++14 graphics engine.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CAMERAOrthographic_H_
#define CAMERAOrthographic_H_

#include <fillwave/space/base/ICamera.h>

namespace fillwave {
namespace framework {

/*! \class CullingBox
 * \brief Stores culling box parameters for Orthographic projection.
 */

struct CullingBox {
	GLfloat mProjectionLeft, mProjectionRight, mProjectionBottom, mProjectionTop,
	        mProjectionNear, mProjectionFar;
};

/*! \class CameraOrthographic
 * \brief Camera with Orthographic projection.
 */

class CameraOrthographic: public ICamera {
 public:
	CameraOrthographic();
	CameraOrthographic(
	   glm::vec3 position,
	   glm::quat rotation,
	   GLfloat left,
	   GLfloat right,
	   GLfloat bottom,
	   GLfloat top,
	   GLfloat near,
	   GLfloat far);
	virtual ~CameraOrthographic() = default;

	void updateProjection();
	GLfloat getProjectionNearPlane();
	GLfloat getProjectionFarPlane();

 private:
	CullingBox mCullingBox;

};

} /* framework */
typedef std::unique_ptr<framework::CameraOrthographic> puCameraOrthographic;
} /* fillwave */

#endif /* CAMERAOrthographic_H_ */
