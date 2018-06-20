#include "xthreejs/helpers/xgrid_helper_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xgrid_helper>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xgrid_helper>;
    template xw::xmaterialize<xthree::xgrid_helper>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xgrid_helper>>;
    template class xw::xgenerator<xthree::xgrid_helper>;
    template xw::xgenerator<xthree::xgrid_helper>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xgrid_helper>>;
#endif
