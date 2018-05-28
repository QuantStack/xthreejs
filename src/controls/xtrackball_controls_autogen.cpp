#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtrackball_controls>;
template xw::xmaterialize<xthree::xtrackball_controls>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtrackball_controls>>;
template class xw::xgenerator<xthree::xtrackball_controls>;
template xw::xgenerator<xthree::xtrackball_controls>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtrackball_controls>>;