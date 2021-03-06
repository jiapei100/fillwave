/*
 * PixelBuffer.h
 *
 *  Created on: Jun 3, 2014
 *      Author: filip
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

#ifndef PIXELBUFFER_H_
#define PIXELBUFFER_H_

#include <fillwave/core/buffers/IBuffer.h>

namespace fillwave {
namespace core {

/*! \class PixelBuffer
 * \brief PixelBufferObject - PBO. Used to read pixels from FBO.
 */

/*
 * When using a PBO as target for glReadPixels
 * you have to specify a byte offset into the buffer
 * just like in glVertexPointer in VBO.
 *
 */

class PixelBuffer: public IBuffer {
 public:
	PixelBuffer(GLuint dataStoreType);
	virtual ~PixelBuffer() = default;
	void setScreenSize(GLuint width, GLuint height, GLuint bytesPerPixel);
	void emptyCPU() override;
	void emptyGPU() override;
};

} /* core */
typedef std::unique_ptr<core::PixelBuffer> puPixelBuffer;
} /* fillwave */

#endif /* PIXELBUFFER_H_ */
