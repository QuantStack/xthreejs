#include "xthreejs/renderers/webgl/xwebgl_state_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_state>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_state>;
    template xw::xmaterialize<xthree::xwebgl_state>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_state>>;
    template class xw::xgenerator<xthree::xwebgl_state>;
    template xw::xgenerator<xthree::xwebgl_state>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_state>>;
#endif
