/*
 * Copyright (c) 2012 cocos2d-x.org
 * http://www.cocos2d-x.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *
 * Converted to c++ / cocos2d-x by Angus C
 */
/*
 *
 * Helper class to store targets and selectors (and eventually, params?) in the same MutableArray. Basically a very crude form of a NSInvocation
 */
#ifndef CC_EXTENSIONS_GUI_CONTROLEXTENSION_INVOCATION_H
#define CC_EXTENSIONS_GUI_CONTROLEXTENSION_INVOCATION_H

#include "../../ExtensionMacros.h"
#include "CCControl.h"
#include "base/CCRef.h"
#include "extensions/ExtensionExport.h"

NS_CC_EXT_BEGIN

/**
 * @addtogroup GUI
 * @{
 * @addtogroup control_extension
 * @{
 */

#define cccontrol_selector(_SELECTOR) static_cast<cocos2d::extension::Control::Handler>(&_SELECTOR)

class CC_EX_DLL Invocation : public Ref
{
public:
    /**
     * @js NA
     * @lua NA
     */
    static Invocation* create(Ref* target, Control::Handler action, Control::EventType controlEvent);
    /**
     * @js NA
     * @lua NA
     */
    Invocation(Ref* target, Control::Handler action, Control::EventType controlEvent);
    /**
     * @js NA
     * @lua NA
     */
    void invoke(Ref* sender);

    Invocation() = default;
    Invocation(Invocation const&) = default;
    Invocation& operator=(Invocation const&) = default;
    Invocation(Invocation&&) noexcept = default;
    Invocation& operator=(Invocation&&) noexcept = default;
    ~Invocation() override;

protected:
    CC_SYNTHESIZE_READONLY(Control::Handler, _action, Action)
    CC_SYNTHESIZE_READONLY(Ref*, _target, Target)
    CC_SYNTHESIZE_READONLY(Control::EventType, _controlEvent, ControlEvent)
};

// end of GUI group
/// @}
/// @}

NS_CC_EXT_END

#endif // CC_EXTENSIONS_GUI_CONTROLEXTENSION_INVOCATION_H
