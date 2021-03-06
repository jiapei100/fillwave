/*
 * BufferSystem.h
 *
 *  Created on: Apr 15, 2016
 *      Author: Filip Wasil
 *
 * Copyright (c) 2016, Fillwave developers
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

#ifndef INC_FILLWAVE_MANAGEMENT_BASE_BUFFERSYSTEM_H_
#define INC_FILLWAVE_MANAGEMENT_BASE_BUFFERSYSTEM_H_

#include <fillwave/core/buffers/IBuffer.h>
#include <fillwave/models/base/IReloadable.h>

namespace fillwave {
namespace framework {

/*! \class BufferSystem
 * \brief Connects VAO pointer and VAO's user pointer in single class.
 */

struct BufferSystem {
	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::VertexArray,
	              IReloadable*> mVertexArrays;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::VertexBufferBasic,
	              core::VertexArray*, framework::TerrainConstructor*, GLint, GLfloat,
	              std::vector<GLuint>&> mVertices;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::IndexBuffer,
	              core::VertexArray*, std::vector<GLuint>&> mIndices;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::VertexBufferText,
	              core::VertexArray*, const std::vector<GLfloat>&, const std::vector<GLfloat>&>
	              mVerticesText;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, std::vector<core::VertexBufferParticlesGPU*>,
	              core::VertexArray*, std::vector<core::VertexParticleGPU>&>
	              mVerticesParticlesGPU;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::VertexBufferParticles,
	              core::VertexArray*, std::vector<GLfloat>&, std::vector<GLfloat>&, std::vector<GLfloat>&>
	              mVerticesParticles;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::VertexBufferDebug,
	              core::VertexArray*, GLfloat> mVerticesDebugger;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::VertexBufferFloat,
	              core::VertexArray*, std::vector<core::VertexFloat>&> mVerticesFloat;

	TManagerSmart<FILLWAVE_MANAGEMENT_MAX_ITEMS, core::VertexBufferPosition,
	              core::VertexArray*, std::vector<core::VertexPosition>&> mVerticesPosition;

};

} /* framework */
} /* fillwave */

#endif /* INC_FILLWAVE_MANAGEMENT_BASE_BUFFERSYSTEM_H_ */
