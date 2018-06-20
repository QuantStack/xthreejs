#include "xthreejs/controls/xtrackball_controls_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xtrackball_controls>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xtrackball_controls>;
    template xw::xmaterialize<xthree::xtrackball_controls>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xtrackball_controls>>;
    template class xw::xgenerator<xthree::xtrackball_controls>;
    template xw::xgenerator<xthree::xtrackball_controls>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xtrackball_controls>>;
#endif
