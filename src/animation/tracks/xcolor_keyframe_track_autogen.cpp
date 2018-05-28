#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcolor_keyframe_track>;
template xw::xmaterialize<xthree::xcolor_keyframe_track>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcolor_keyframe_track>>;
template class xw::xgenerator<xthree::xcolor_keyframe_track>;
template xw::xgenerator<xthree::xcolor_keyframe_track>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcolor_keyframe_track>>;