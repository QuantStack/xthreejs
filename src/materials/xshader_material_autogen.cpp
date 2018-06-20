#include "xthreejs/materials/xshader_material_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xshader_material>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xshader_material>;
    template xw::xmaterialize<xthree::xshader_material>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xshader_material>>;
    template class xw::xgenerator<xthree::xshader_material>;
    template xw::xgenerator<xthree::xshader_material>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xshader_material>>;
#endif
