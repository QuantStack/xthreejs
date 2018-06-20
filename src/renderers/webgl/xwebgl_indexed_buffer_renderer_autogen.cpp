#include "xthreejs/renderers/webgl/xwebgl_indexed_buffer_renderer_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_indexed_buffer_renderer>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_indexed_buffer_renderer>;
    template xw::xmaterialize<xthree::xwebgl_indexed_buffer_renderer>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_indexed_buffer_renderer>>;
    template class xw::xgenerator<xthree::xwebgl_indexed_buffer_renderer>;
    template xw::xgenerator<xthree::xwebgl_indexed_buffer_renderer>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_indexed_buffer_renderer>>;
#endif
