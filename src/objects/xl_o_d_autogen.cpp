#include "xthreejs/objects/xl_o_d_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xl_o_d>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xl_o_d>;
    template xw::xmaterialize<xthree::xl_o_d>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xl_o_d>>;
    template class xw::xgenerator<xthree::xl_o_d>;
    template xw::xgenerator<xthree::xl_o_d>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xl_o_d>>;
#endif
