#include "xthreejs/objects/xskinned_mesh_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xskinned_mesh>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xskinned_mesh>;
    template xw::xmaterialize<xthree::xskinned_mesh>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xskinned_mesh>>;
    template class xw::xgenerator<xthree::xskinned_mesh>;
    template xw::xgenerator<xthree::xskinned_mesh>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xskinned_mesh>>;
#endif
