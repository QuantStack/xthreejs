#include "xthreejs/cameras/xcamera_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcamera>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcamera>;
    template xw::xmaterialize<xthree::xcamera>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcamera>>;
    template class xw::xgenerator<xthree::xcamera>;
    template xw::xgenerator<xthree::xcamera>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcamera>>;
#endif
