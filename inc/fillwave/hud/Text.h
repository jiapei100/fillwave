/*
 * Text.h
 *
 *  Created on: Jul 26, 2014
 *      Author: Filip Wasil
 */

#ifndef TEXT_H_
#define TEXT_H_

#include <fillwave/core/texturing/TextureRegion.h>
#include <fillwave/core/buffers/VertexBufferText.h>
#include <fillwave/core/pipeline/Program.h>

#include <fillwave/common/Blending.h>

#include <fillwave/loaders/FontLoader.h>
#include <fillwave/models/base/Reloadable.h>
#include <fillwave/hud/base/IHUD.h>

#include <map>

namespace fillwave {
class Engine;

enum class eTextEffect {
	eNone, eBold
};

namespace framework {

/*! \class Text
 * \brief 2D Text on the screen.
 */

class Text: public Reloadable, public IHUD {
public:
	Text(
			std::string& text,
			pTexture2D texture,
			GLfloat startingPositionX,
			GLfloat startingPositionY,
			Engine* engine,
			GLfloat scale,
			Font* font,
			glm::vec4 color = glm::vec4(1.0, 1.0, 1.0, 1.0),
			eTextEffect effect = eTextEffect::eNone);

	virtual ~Text() = default;

	void draw() override;

	void editAspectRatio(Engine* engine);
	void editString(std::string text);
	void editColor(glm::vec4 color);
	void editSize(GLfloat size);
	void editPosition(GLfloat startingX, GLfloat startingY);

private:
	Engine* mEngine;

	std::string mText;

	Blending mBlending;

	std::map<std::string, pTextureRegion> mCharacters;

	pTexture mTexture;

	pProgram mProgram;
	GLint mViewportWidth, mViewportHeight;
	pVertexBufferText mVBO;
	GLfloat mStartingX, mStartingY, mScale;
	Font* mFont;
	glm::vec4 mColor;
	eTextEffect mEffect;

	GLint mUniformLocationCacheColor, mUniformLocationCacheTextureUnit;

	void createProgram();
	void createVBO();
	void clearVBO();

	void initVBO();
	void initVAO();
	void initBuffers();
	void initPipeline();
	void initUniformsCache();
};

} /* framework */
typedef std::shared_ptr<framework::Text> pText;
typedef std::unique_ptr<framework::Text> puText;
} /* fillwave */

#endif /* TEXT_H_ */