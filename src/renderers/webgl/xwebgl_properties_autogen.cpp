#include "xthreejs/renderers/webgl/xwebgl_properties_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_properties>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_properties>;
    template xw::xmaterialize<xthree::xwebgl_properties>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_properties>>;
    template class xw::xgenerator<xthree::xwebgl_properties>;
    template xw::xgenerator<xthree::xwebgl_properties>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_properties>>;
#endif
