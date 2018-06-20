#include "xthreejs/objects/xmesh_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmesh>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xmesh>;
    template xw::xmaterialize<xthree::xmesh>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xmesh>>;
    template class xw::xgenerator<xthree::xmesh>;
    template xw::xgenerator<xthree::xmesh>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xmesh>>;
#endif
