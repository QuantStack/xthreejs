#include "xthreejs/scenes/xfog_exp2_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfog_exp2>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xfog_exp2>;
    template xw::xmaterialize<xthree::xfog_exp2>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xfog_exp2>>;
    template class xw::xgenerator<xthree::xfog_exp2>;
    template xw::xgenerator<xthree::xfog_exp2>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xfog_exp2>>;
#endif
