#include "xthreejs/renderers/webgl/xwebgl_lights_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_lights>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_lights>;
    template xw::xmaterialize<xthree::xwebgl_lights>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_lights>>;
    template class xw::xgenerator<xthree::xwebgl_lights>;
    template xw::xgenerator<xthree::xwebgl_lights>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_lights>>;
#endif
