#include "xthreejs/helpers/xcamera_helper_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcamera_helper>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcamera_helper>;
    template xw::xmaterialize<xthree::xcamera_helper>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcamera_helper>>;
    template class xw::xgenerator<xthree::xcamera_helper>;
    template xw::xgenerator<xthree::xcamera_helper>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcamera_helper>>;
#endif
