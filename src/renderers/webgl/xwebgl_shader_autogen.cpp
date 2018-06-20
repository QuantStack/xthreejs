#include "xthreejs/renderers/webgl/xwebgl_shader_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_shader>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_shader>;
    template xw::xmaterialize<xthree::xwebgl_shader>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_shader>>;
    template class xw::xgenerator<xthree::xwebgl_shader>;
    template xw::xgenerator<xthree::xwebgl_shader>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_shader>>;
#endif
