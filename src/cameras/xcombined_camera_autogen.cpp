#include "xthreejs/cameras/xcombined_camera_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcombined_camera>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcombined_camera>;
    template xw::xmaterialize<xthree::xcombined_camera>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcombined_camera>>;
    template class xw::xgenerator<xthree::xcombined_camera>;
    template xw::xgenerator<xthree::xcombined_camera>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcombined_camera>>;
#endif
