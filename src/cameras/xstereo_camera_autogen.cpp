#include "xthreejs/cameras/xstereo_camera_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xstereo_camera>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xstereo_camera>;
    template xw::xmaterialize<xthree::xstereo_camera>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xstereo_camera>>;
    template class xw::xgenerator<xthree::xstereo_camera>;
    template xw::xgenerator<xthree::xstereo_camera>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xstereo_camera>>;
#endif
