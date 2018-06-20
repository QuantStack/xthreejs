#include "xthreejs/renderers/webgl/xwebgl_programs_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_programs>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_programs>;
    template xw::xmaterialize<xthree::xwebgl_programs>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_programs>>;
    template class xw::xgenerator<xthree::xwebgl_programs>;
    template xw::xgenerator<xthree::xwebgl_programs>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_programs>>;
#endif
