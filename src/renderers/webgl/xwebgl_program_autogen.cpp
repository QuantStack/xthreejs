#include "xthreejs/renderers/webgl/xwebgl_program_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_program>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_program>;
    template xw::xmaterialize<xthree::xwebgl_program>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_program>>;
    template class xw::xgenerator<xthree::xwebgl_program>;
    template xw::xgenerator<xthree::xwebgl_program>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_program>>;
#endif
