#include "xthreejs/core/xinterleaved_buffer_attribute_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xinterleaved_buffer_attribute>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xinterleaved_buffer_attribute>;
    template xw::xmaterialize<xthree::xinterleaved_buffer_attribute>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xinterleaved_buffer_attribute>>;
    template class xw::xgenerator<xthree::xinterleaved_buffer_attribute>;
    template xw::xgenerator<xthree::xinterleaved_buffer_attribute>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xinterleaved_buffer_attribute>>;
#endif
