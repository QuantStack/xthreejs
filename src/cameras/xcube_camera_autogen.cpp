#include "xthreejs/cameras/xcube_camera_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcube_camera>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcube_camera>;
    template xw::xmaterialize<xthree::xcube_camera>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcube_camera>>;
    template class xw::xgenerator<xthree::xcube_camera>;
    template xw::xgenerator<xthree::xcube_camera>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcube_camera>>;
#endif
