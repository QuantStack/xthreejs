#include "xthreejs/cameras/xarray_camera_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xarray_camera>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xarray_camera>;
    template xw::xmaterialize<xthree::xarray_camera>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xarray_camera>>;
    template class xw::xgenerator<xthree::xarray_camera>;
    template xw::xgenerator<xthree::xarray_camera>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xarray_camera>>;
#endif
