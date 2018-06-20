#include "xthreejs/extras/core/xshape_path_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xshape_path>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xshape_path>;
    template xw::xmaterialize<xthree::xshape_path>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xshape_path>>;
    template class xw::xgenerator<xthree::xshape_path>;
    template xw::xgenerator<xthree::xshape_path>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xshape_path>>;
#endif
