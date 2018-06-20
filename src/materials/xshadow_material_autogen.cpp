#include "xthreejs/materials/xshadow_material_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xshadow_material>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xshadow_material>;
    template xw::xmaterialize<xthree::xshadow_material>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xshadow_material>>;
    template class xw::xgenerator<xthree::xshadow_material>;
    template xw::xgenerator<xthree::xshadow_material>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xshadow_material>>;
#endif
