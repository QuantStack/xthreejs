#include "xthreejs/animation/xanimation_object_group_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xanimation_object_group>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xanimation_object_group>;
    template xw::xmaterialize<xthree::xanimation_object_group>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xanimation_object_group>>;
    template class xw::xgenerator<xthree::xanimation_object_group>;
    template xw::xgenerator<xthree::xanimation_object_group>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xanimation_object_group>>;
#endif
