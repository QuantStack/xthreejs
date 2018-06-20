#include "xthreejs/materials/xmesh_physical_material_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmesh_physical_material>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xmesh_physical_material>;
    template xw::xmaterialize<xthree::xmesh_physical_material>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xmesh_physical_material>>;
    template class xw::xgenerator<xthree::xmesh_physical_material>;
    template xw::xgenerator<xthree::xmesh_physical_material>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xmesh_physical_material>>;
#endif
