#include "xthreejs/objects/xline_loop_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xline_loop>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xline_loop>;
    template xw::xmaterialize<xthree::xline_loop>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xline_loop>>;
    template class xw::xgenerator<xthree::xline_loop>;
    template xw::xgenerator<xthree::xline_loop>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xline_loop>>;
#endif
