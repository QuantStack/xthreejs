#include "xthreejs/renderers/webgl/xwebgl_extensions_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_extensions>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_extensions>;
    template xw::xmaterialize<xthree::xwebgl_extensions>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_extensions>>;
    template class xw::xgenerator<xthree::xwebgl_extensions>;
    template xw::xgenerator<xthree::xwebgl_extensions>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_extensions>>;
#endif
