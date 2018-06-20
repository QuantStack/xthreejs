#include "xthreejs/extras/core/xcurve_path_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcurve_path>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcurve_path>;
    template xw::xmaterialize<xthree::xcurve_path>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcurve_path>>;
    template class xw::xgenerator<xthree::xcurve_path>;
    template xw::xgenerator<xthree::xcurve_path>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcurve_path>>;
#endif
