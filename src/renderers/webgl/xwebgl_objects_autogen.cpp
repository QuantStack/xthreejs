#include "xthreejs/renderers/webgl/xwebgl_objects_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_objects>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_objects>;
    template xw::xmaterialize<xthree::xwebgl_objects>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_objects>>;
    template class xw::xgenerator<xthree::xwebgl_objects>;
    template xw::xgenerator<xthree::xwebgl_objects>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_objects>>;
#endif
