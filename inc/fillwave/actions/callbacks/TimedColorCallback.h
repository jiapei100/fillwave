/*
 * TimedColorCallback.h
 *
 *  Created on: 11 lut 2015
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

#ifndef INC_FILLWAVE_ACTIONS_TIMEDCOLORCALLBACK_H_
#define INC_FILLWAVE_ACTIONS_TIMEDCOLORCALLBACK_H_

#include <fillwave/actions/callbacks/TimedCallback.h>
#include <fillwave/models/Model.h>
#include <fillwave/models/effects/Painter.h>

namespace fillwave {
namespace framework {

/*! \class TimedColorCallback
 * \brief TimedCallback to change Entity color in time.
 */

class TimedColorCallback: public TimedCallback {
 public:
	TimedColorCallback(
	   Model* model,
	   glm::vec4 endColor,
	   GLfloat lifeTime,
	   EasingFunction easing);

	virtual ~TimedColorCallback() = default;

	/*	perform
	 * \brief Performs ItemCallback action
	 */

	void perform(EventType& eventType);

 private:
	glm::vec4 mStartColor;
	glm::vec4 mEndColor;
	Model* mModel;
	pPainter mPainter;
};

} /* framework */
} /* fillwave */

#endif /* INC_FILLWAVE_ACTIONS_TIMEDCOLORCALLBACK_H_ */
