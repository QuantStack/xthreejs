#include "xthreejs/scenes/xscene_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xscene>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xscene>;
    template xw::xmaterialize<xthree::xscene>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xscene>>;
    template class xw::xgenerator<xthree::xscene>;
    template xw::xgenerator<xthree::xscene>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xscene>>;
#endif
