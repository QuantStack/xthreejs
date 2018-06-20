#include "xthreejs/helpers/xpolar_grid_helper_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xpolar_grid_helper>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xpolar_grid_helper>;
    template xw::xmaterialize<xthree::xpolar_grid_helper>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xpolar_grid_helper>>;
    template class xw::xgenerator<xthree::xpolar_grid_helper>;
    template xw::xgenerator<xthree::xpolar_grid_helper>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xpolar_grid_helper>>;
#endif
