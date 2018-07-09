/****************************************************************************
 Copyright (C) 2013 Henry van Merode. All rights reserved.
 Copyright (c) 2015 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef CC_EXTENSIONS_PARTICLE3D_PU_LINEEMITTER_H
#define CC_EXTENSIONS_PARTICLE3D_PU_LINEEMITTER_H

#include "extensions/Particle3D/PU/CCPUEmitter.h"

NS_CC_BEGIN

struct PUParticle3D;
class CC_DLL PULineEmitter : public PUEmitter
{
public:
    // Constants
    static const Vec3 DEFAULT_END;
    static const float DEFAULT_MIN_INCREMENT;
    static const float DEFAULT_MAX_INCREMENT;
    static const float DEFAULT_MAX_DEVIATION;

    static PULineEmitter* create();
    /**
     */
    void notifyStart(void) override;

    /** Override the default implementation, to allow that no particles are emitted if there
        is an incremental emission of particles (along a path), and the end of the line has
        been reached.
    */
    unsigned short calculateRequestedParticles(float timeElapsed) override;

    /**
     */
    float getMaxDeviation(void) const;
    void setMaxDeviation(float maxDeviation);

    /**
     */
    float getMaxIncrement(void) const;
    void setMaxIncrement(float maxIncrement);

    /**
     */
    float getMinIncrement(void) const;
    void setMinIncrement(float minIncrement);

    /** Get the end vector. This is the vector that defines the end of the line (in local space).
     */
    const Vec3& getEnd(void) const;

    /** Set the end vector.
     */
    void setEnd(const Vec3& end);

    /**
     */
    void notifyRescaled(const Vec3& scale) override;

    /**
     */
    void initParticlePosition(PUParticle3D* particle) override;

    /**
     */
    void initParticleDirection(PUParticle3D* particle) override;

    PULineEmitter* clone() override;
    void copyAttributesTo(PUEmitter* emitter) override;

    CC_CONSTRUCTOR_ACCESS : PULineEmitter();
    ~PULineEmitter() override = default;

protected:
    Vec3 _end; // End point of the line (startpoint is determined by means of position)
    Vec3 _perpendicular; // Generated unit vector perpendicular on the line
    float _maxDeviation; // Determines how far from the line a particle is emitted.
    // This attribute defines the maximum value.
    float _minIncrement; // Defines the minimum increment value.
    float _maxIncrement; // If > 0, it defines the maximum (random) increment value that is
    // taken on the line traject. If not set, there is no particular
    // order in particle generation.
    float _increment; // Defines the trajectory path along the line in terms of increments
    float _length; // The length of the line
    bool _incrementsLeft; // Indicates whether there are more increments on the path towards the end
    // of the line.
    bool _first; // True when the first particle is emitted (only for generating particles incremental)

    // Internal scaled values
    Vec3 _scaledEnd;
    float _scaledMaxDeviation;
    float _scaledMinIncrement;
    float _scaledMaxIncrement;
    float _scaledLength;
};
NS_CC_END

#endif // CC_EXTENSIONS_PARTICLE3D_PU_LINEEMITTER_H
