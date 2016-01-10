/*
 * Hinge.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: filip
 */

#include <fillwave/models/animations/Hinge.h>

namespace fillwave {
namespace framework {

void Hinge::draw(ICamera& camera) {
	for (auto& it : mChildren) {
		it->draw(camera);
	}
}

void Hinge::drawPBRP(ICamera& camera) {
	for (auto& it : mChildren) {
		it->drawPBRP(camera);
	}
}

void Hinge::drawDR(ICamera& camera) {
	for (auto& it : mChildren) {
		it->drawDR(camera);
	}
}

void Hinge::updateRenderer(IRenderer& /*renderer*/) {
	/* Hinge is not renderable */ //xxx add renderable class
}

} /* namespace framework */
} /* namespace fillwave */