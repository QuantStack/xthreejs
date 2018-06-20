#include "xthreejs/helpers/xaxes_helper_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xaxes_helper>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xaxes_helper>;
    template xw::xmaterialize<xthree::xaxes_helper>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xaxes_helper>>;
    template class xw::xgenerator<xthree::xaxes_helper>;
    template xw::xgenerator<xthree::xaxes_helper>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xaxes_helper>>;
#endif
