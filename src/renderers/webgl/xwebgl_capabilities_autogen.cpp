#include "xthreejs/renderers/webgl/xwebgl_capabilities_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_capabilities>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_capabilities>;
    template xw::xmaterialize<xthree::xwebgl_capabilities>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_capabilities>>;
    template class xw::xgenerator<xthree::xwebgl_capabilities>;
    template xw::xgenerator<xthree::xwebgl_capabilities>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_capabilities>>;
#endif
