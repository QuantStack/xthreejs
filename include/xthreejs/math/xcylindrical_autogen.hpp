#ifndef XTHREE_CYLINDRICAL_HPP
#define XTHREE_CYLINDRICAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // cylindrical declaration
    //

    template<class D>
    class xcylindrical : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(double, derived_type, theta, 0);
        XPROPERTY(double, derived_type, y, 0);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcylindrical();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cylindrical = xw::xmaterialize<xcylindrical>;

    using cylindrical_generator = xw::xgenerator<xcylindrical>;

    //
    // cylindrical implementation
    //


    template <class D>
    inline void xcylindrical<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(theta, state, buffers);
        xw::set_patch_from_property(y, state, buffers);
    }

    template <class D>
    inline void xcylindrical<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(theta, patch, buffers);
        xw::set_property_from_patch(y, patch, buffers);
    }

    template <class D>
    inline xcylindrical<D>::xcylindrical()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcylindrical<D>::set_defaults()
    {
        this->_model_name() = "CylindricalModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcylindrical>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xcylindrical>;
        extern template xw::xmaterialize<xthree::xcylindrical>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcylindrical>>;
        extern template class xw::xgenerator<xthree::xcylindrical>;
        extern template xw::xgenerator<xthree::xcylindrical>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcylindrical>>;
    #endif
#endif

#endif