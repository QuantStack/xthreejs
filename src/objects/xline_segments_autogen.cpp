#include "xthreejs/objects/xline_segments_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xline_segments>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xline_segments>;
    template xw::xmaterialize<xthree::xline_segments>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xline_segments>>;
    template class xw::xgenerator<xthree::xline_segments>;
    template xw::xgenerator<xthree::xline_segments>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xline_segments>>;
#endif
