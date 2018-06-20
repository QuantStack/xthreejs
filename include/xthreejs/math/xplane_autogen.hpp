#ifndef XTHREE_PLANE_BASE_HPP
#define XTHREE_PLANE_BASE_HPP

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
    // plane_base declaration
    //

    template<class D>
    class xplane_base : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, normal, vector3({0,0,0}));
        XPROPERTY(double, derived_type, constant, 0);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xplane_base();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using plane_base = xw::xmaterialize<xplane_base>;

    using plane_base_generator = xw::xgenerator<xplane_base>;

    //
    // plane_base implementation
    //


    template <class D>
    inline void xplane_base<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(normal, state, buffers);
        xw::set_patch_from_property(constant, state, buffers);
    }

    template <class D>
    inline void xplane_base<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(normal, patch, buffers);
        xw::set_property_from_patch(constant, patch, buffers);
    }

    template <class D>
    inline xplane_base<D>::xplane_base()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xplane_base<D>::set_defaults()
    {
        this->_model_name() = "PlaneBaseModel";
        this->_view_name() = "";
    }
}


/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xplane_base>;
        extern template xw::xmaterialize<xthree::xplane_base>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xplane_base>>;
        extern template class xw::xgenerator<xthree::xplane_base>;
        extern template xw::xgenerator<xthree::xplane_base>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xplane_base>>;
    #endif
#endif

#endif